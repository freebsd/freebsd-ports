
#include <sys/types.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dev/usb/usb.h>

#include "RCX_Pipe.h"

#include "PDebug.h"

#define kVendorID 1684
#define kProductID 1
#define kConfiguration 0
#define kReadPipe 1
#define kWritePipe 2

// these should come from a LEGO include
#define LTW_REQ_GET_PARM	1
#define LTW_REQ_SET_PARM	2
#define LTW_PARM_RANGE		2
#define LTW_RANGE_SHORT		1
#define LTW_RANGE_MEDIUM	2


#define LTW_REQ_SET_TX_SPEED	0xEF
#define LTW_REQ_SET_RX_SPEED	0xF1

#define SPEED_COMM_BAUD_2400	8	
#define SPEED_COMM_BAUD_4800	0x10

#define LTW_REQ_SET_TX_CARRIER_FREQUENCY	0xF4 

#define UInt32	uint32_t
#define UInt16	uint16_t
#define UInt8	uint8_t
#define IOReturn	int

typedef struct LTW_REQ_REPLY_HEADER {
	UInt16 wNoOfBytes;			// Number of bytes in the reply
	UInt8 bErrCode;				// Request return code
	UInt8 bValue;				// Request return value
} LTW_REQ_REPLY_HEADER; 

typedef LTW_REQ_REPLY_HEADER LTW_REQ_GET_SET_PARM_REPLY;

class RCX_USBTowerPipe_fbsd : public RCX_Pipe
{
public:
	RCX_USBTowerPipe_fbsd();
	~RCX_USBTowerPipe_fbsd()	{ Close(); }

	virtual RCX_Result	Open(const char *name, int mode);
	virtual void		Close();

	virtual int		GetCapabilities() const;
	virtual RCX_Result	SetMode(int mode);

	virtual long		Read(void *ptr, long count, long timeout_ms);
	virtual long		Write(const void *ptr, long count);

private:
	enum {
		kReadPacketSize = 8
	};
	
	IOReturn	OpenDevice(short vendorID, short productID);
	IOReturn	OpenInterface();
	IOReturn	ControlRequest(UInt8 request, UInt16 value);
	IOReturn	ControlRequest(UInt8 request, UInt8 loByte, UInt8 hiByte) {
		return ControlRequest(request, loByte + (hiByte << 8));
	}

	int fdCntrl;
	int fdRd;
	int fdWr;

	char *devname;
};


RCX_Pipe* RCX_NewUSBTowerPipe()
{
	return new RCX_USBTowerPipe_fbsd();
}


RCX_USBTowerPipe_fbsd::RCX_USBTowerPipe_fbsd()
	: fdCntrl(0), devname(0)
{
}


RCX_Result RCX_USBTowerPipe_fbsd::Open(const char *name, int mode)
{
	IOReturn err;

	if (mode != kNormalIrMode) return kRCX_PipeModeError;

	err = OpenDevice(kVendorID, kProductID);
	PREQUIRENOT(err, Fail_OpenDevice);

	err = OpenInterface();
	PREQUIRENOT(err, Fail_OpenInterface);

	UInt8 range;
	range = (strcmp(name, "short")==0) ? LTW_RANGE_SHORT : LTW_RANGE_MEDIUM;
	ControlRequest(LTW_REQ_SET_PARM, LTW_PARM_RANGE,range);

	return 0;

Fail_OpenInterface:
Fail_OpenDevice:
	Close();
	return kRCX_OpenSerialError;
}


void RCX_USBTowerPipe_fbsd::Close()
{
	if (devname != NULL) {
		close(fdWr);
		close(fdRd);
		close(fdCntrl);
		devname = NULL;
	}
}


int RCX_USBTowerPipe_fbsd::GetCapabilities() const
{
	return kNormalIrMode | kFastIrMode | kFastOddParityFlag | kAbsorb55Flag;
}


RCX_Result RCX_USBTowerPipe_fbsd::SetMode(int mode)
{
	switch(mode) {
	case kNormalIrMode:
		ControlRequest(LTW_REQ_SET_TX_SPEED, SPEED_COMM_BAUD_2400);
		ControlRequest(LTW_REQ_SET_RX_SPEED, SPEED_COMM_BAUD_2400);
		return kRCX_OK;
	case kFastIrMode:
		ControlRequest(LTW_REQ_SET_PARM, LTW_PARM_RANGE, LTW_RANGE_SHORT);
		ControlRequest(LTW_REQ_SET_TX_SPEED, SPEED_COMM_BAUD_4800);
		ControlRequest(LTW_REQ_SET_RX_SPEED, SPEED_COMM_BAUD_4800);
		ControlRequest(LTW_REQ_SET_TX_CARRIER_FREQUENCY, 38);
		return kRCX_OK;
	default:
		return kRCX_PipeModeError;
	}
}


#define MAX_PACKET 200

long RCX_USBTowerPipe_fbsd::Write(const void *ptr, long length)
{
	const unsigned char *data = (const unsigned char *)ptr;
	
	int total = 0;
	
//	printf("Write %ld\n", length);

	while(length > 0) {
		IOReturn err;
		int count = length;
		if (count > MAX_PACKET)
			count = MAX_PACKET;
		err = write(fdWr, (void *)data, count);
		if (err == count)
			err = 0;
		PREQUIRENOT(err, Fail_WritePipe);
		
		length -= count;
		data += count;
		total += count;
	}
	
Fail_WritePipe:
//	printf("Done %d\n", total);
	return total;
}



long RCX_USBTowerPipe_fbsd::Read(void *data, long length, long timeout_ms)
{
	const unsigned char *rdptr = (const unsigned char *)data;
	IOReturn err;
	int count;
	int total = 0;
	struct pollfd pfd;

//	printf("Read %ld, timeout %ld\n", length, timeout_ms);
	while(length > 0) {
		pfd.fd = fdRd;
		pfd.events = POLLIN;
		err = poll(&pfd, 1, timeout_ms);
		if (err == 0)
			break;
		if (err == -1) {
			if(errno == EINTR)
				continue;
			else
				break;
		}
		count = length;
		if (count > MAX_PACKET)
			count = MAX_PACKET;
		err = read(fdRd, (void *)rdptr, count);
		if (err == -1)
			break;

//		printf("err %d\n", err);
		if (err == 0 || err == -1)
			goto Fail_ReadPipe;

		count = err;
		length -= count;
		rdptr += count;
		total += count;
	}

Fail_ReadPipe:
//	printf("Got %d\n", total);
	return total;
}


IOReturn RCX_USBTowerPipe_fbsd::OpenDevice(short vendorID, short productID)
{
	char *dn = "/dev/ugen0";
	int err, fd;
	usb_device_descriptor_t usbdd;

	fd = open(dn, O_RDWR);
	if (fd == -1)
		return errno;
	err = ioctl(fd, USB_GET_DEVICE_DESC, &usbdd);
	if (err == -1) {
		perror("ioctl error");
		return errno;
	}
//	printf("idVendor %d\n", UGETW(usbdd.idVendor));
//	printf("idProduct %d\n", UGETW(usbdd.idProduct));
	if (UGETW(usbdd.idVendor) != kVendorID ||
	    UGETW(usbdd.idProduct) != kProductID) {
		fprintf(stderr, "This is not an USB IR Tower!\n");
		return -1;
	}

	devname = dn;
	fdCntrl = fd;

	return 0;
}


IOReturn RCX_USBTowerPipe_fbsd::OpenInterface()
{
	char *dn;
	int err, iov;

	dn = (char *)malloc(strlen(devname) + 2 + 1);
	strcpy(dn, devname);
	strcat(dn, ".1");
	fdRd = open(dn, O_RDONLY|O_NONBLOCK);
	if (fdRd == -1) {
		perror(dn);
		return -1;
	}
	iov = 1;
	err = ioctl(fdRd, USB_SET_SHORT_XFER, &iov);
	if (fdRd == -1) {
		perror("ioctl USB_SET_SHORT_XFER");
		return -1;
	}
	iov = 5000;
	err = ioctl(fdRd, USB_SET_TIMEOUT, &iov);
	if (fdRd == -1) {
		perror("ioctl USB_SET_TIMEOUT");
		return -1;
	}

	strcpy(dn, devname);
	strcat(dn, ".2");
	fdWr = open(dn, O_WRONLY);
	iov = 5000;
//	ioctl(fdWr, USB_SET_TIMEOUT, &iov);

	return 0;
}


IOReturn RCX_USBTowerPipe_fbsd::ControlRequest(UInt8 request, UInt16 value)
{
	IOReturn err;
	struct usb_ctl_request req;
	LTW_REQ_GET_SET_PARM_REPLY reply;
	
	req.ucr_request.bmRequestType = UT_READ_VENDOR_DEVICE;
	req.ucr_request.bRequest = request;
	USETW(req.ucr_request.wValue, value);
	USETW(req.ucr_request.wIndex, 0);
	USETW(req.ucr_request.wLength, sizeof(reply));
	req.ucr_data = &reply;
	
	err = ioctl(fdCntrl, USB_DO_REQUEST, &req);

	// size of actual reply in req.wLenDone	
	//printf("%d %d %d\n", reply.wNoOfBytes, reply.bErrCode, reply.bValue);

	return err;
}

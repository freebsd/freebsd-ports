/*
 * Copyright (C) 2011 Hans Petter Selasky. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libusb.h>

#include <memory>

#include "usb.h"

struct usb_handle {
	libusb_device_handle *handle;
	libusb_device *dev;
	unsigned char ep_in;
	unsigned char ep_out;
	unsigned char iface;
};

class LibusbUsbTransport : public Transport {
public:
	explicit LibusbUsbTransport(std::unique_ptr<usb_handle> handle):
		h(std::move(handle)) {}
	~LibusbUsbTransport() override = default;

	ssize_t Read(void *_data, size_t len) override;
	ssize_t Write(const void *_data, size_t len) override;
	int Close() override;

private:
	std::unique_ptr<usb_handle> h;

	DISALLOW_COPY_AND_ASSIGN(LibusbUsbTransport);
};

static int 
probe(std::unique_ptr<usb_handle> &h, ifc_match_func callback)
{
	usb_ifc_info info;
	libusb_device_descriptor ddesc;
	libusb_config_descriptor *pcfg;
	int i, j;

	if (libusb_open(h->dev, &h->handle) < 0)
		return (-1);

	if (libusb_get_device_descriptor(h->dev, &ddesc) < 0) {
		libusb_close(h->handle);
		return (-1);
	}
	memset(&info, 0, sizeof(info));

	info.dev_vendor = ddesc.idVendor;
	info.dev_product = ddesc.idProduct;
	info.dev_class = ddesc.bDeviceClass;
	info.dev_subclass = ddesc.bDeviceSubClass;
	info.dev_protocol = ddesc.bDeviceProtocol;
	info.writable = 1;

	snprintf(info.device_path, sizeof(info.device_path), "usb:%d:%d",
		 libusb_get_bus_number(h->dev), libusb_get_device_address(h->dev));

	if (ddesc.iSerialNumber != 0) {
		libusb_get_string_descriptor_ascii(h->handle, ddesc.iSerialNumber,
		    (unsigned char *)info.serial_number, sizeof(info.serial_number));
	}
	if (libusb_get_active_config_descriptor(h->dev, &pcfg)) {
		libusb_close(h->handle);
		return (-1);
	}

	for (i = 0; i < pcfg->bNumInterfaces; i++) {

		h->ep_in = 0;
		h->ep_out = 0;
		h->iface = i;

		for (j = 0; j < pcfg->interface[i].altsetting[0].bNumEndpoints; j++) {

			unsigned char temp = pcfg->interface[i].altsetting[0].
			endpoint[j].bEndpointAddress;
			unsigned char type = pcfg->interface[i].altsetting[0].
			endpoint[j].bmAttributes & 0x03;

			/* check for BULK endpoint */
			if ((type & 0x03) == 0x02) {
				/* check for IN endpoint */
				if (temp & 0x80)
					h->ep_in = temp;
				else
					h->ep_out = temp;
			}
		}

		info.ifc_class = pcfg->interface[i].altsetting[0].bInterfaceClass;
		info.ifc_subclass = pcfg->interface[i].altsetting[0].bInterfaceSubClass;
		info.ifc_protocol = pcfg->interface[i].altsetting[0].bInterfaceProtocol;
		info.has_bulk_in = (h->ep_in != 0);
		info.has_bulk_out = (h->ep_out != 0);

		if (libusb_claim_interface(h->handle, h->iface) < 0)
			continue;

		if (callback(&info) == 0) {
			libusb_free_config_descriptor(pcfg);
			return (0);
		}
		libusb_release_interface(h->handle, h->iface);
	}

	libusb_free_config_descriptor(pcfg);
	libusb_close(h->handle);
	return (-1);
}

static std::unique_ptr<usb_handle>
enumerate(ifc_match_func callback)
{
	static libusb_context *ctx = NULL;
	std::unique_ptr<usb_handle> h;
	libusb_device **ppdev;
	ssize_t ndev;
	ssize_t x;

	if (ctx == NULL)
		libusb_init(&ctx);

	ndev = libusb_get_device_list(ctx, &ppdev);
	for (x = 0; x < ndev; x++) {

		h.reset(new usb_handle);

		h->dev = ppdev[x];

		if (probe(h, callback) == 0) {
			libusb_ref_device(h->dev);
			libusb_free_device_list(ppdev, 1);
			return (h);
		}
	}
	h.reset();
	libusb_free_device_list(ppdev, 1);
	return (nullptr);
}

ssize_t
LibusbUsbTransport::Write(const void *_data, size_t len)
{
	int actlen;

	if (libusb_bulk_transfer(h->handle, h->ep_out,
				 (unsigned char *)_data, len, &actlen, 0) < 0)
		return (-1);
	return (actlen);
}

ssize_t
LibusbUsbTransport::Read(void *_data, size_t len)
{
	int actlen;

	if (libusb_bulk_transfer(h->handle, h->ep_in,
				 (unsigned char *)_data, len, &actlen, 0) < 0)
		return (-1);
	return (actlen);
}

int
LibusbUsbTransport::Close()
{
	libusb_close(h->handle);
	h->handle = NULL;
	libusb_unref_device(h->dev);
	h.reset();
	return (0);
}

Transport *
usb_open(ifc_match_func callback)
{
	std::unique_ptr<usb_handle> h = enumerate(callback);
	return (h ? new LibusbUsbTransport(std::move(h)) : nullptr);
}

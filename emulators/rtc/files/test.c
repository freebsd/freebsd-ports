#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioccom.h>

#include "rtc.h"


int main(void)
{
	int rtc;
	fd_set rset;
	int i,rc;
	int ntests=100;
	struct timeval tv;
	struct timeval begin,end,delta;


	rtc = open("/dev/rtc", O_RDONLY);	
	if (rtc<0) {
		perror("/dec/rtc");
		return 1;
	}

	rc = ioctl(rtc, RTCIO_IRQP_SET, 512);
	if (rc<0) {
		perror("/dev/rtc");
		return 1;
	}

	rc = ioctl(rtc, RTCIO_PIE_ON, NULL);
	if (rc<0) {
		perror("/dev/rtc");
		return 1;
	}
	
	gettimeofday(&begin, NULL);	
	for (i=0; i<ntests; i++) {
		FD_ZERO(&rset);
		FD_SET(rtc, &rset);
		tv.tv_sec=0;
		tv.tv_usec=10000;
		rc=select(rtc+1, &rset, NULL, NULL, &tv);
	}	
	gettimeofday(&end, NULL);
	timersub(&end, &begin, &delta);
	printf("time %ld msec per test\n", (delta.tv_sec*1000+delta.tv_usec/1000)/ntests);
	return 0;
}

	



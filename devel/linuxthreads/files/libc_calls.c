/*
 * Copyright (c) 1998 Richard Seaman, Jr.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by Richard Seaman, Jr.
 * 4. Neither the name of the author nor the names of any co-contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY RICHARD SEAMAN, Jr. AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/ttycom.h>
#include <osreldate.h>
#include <time.h>
#include "pthread.h"
#include "internals.h"

#ifndef NEWLIBC

char * asctime (const struct tm *timeptr)
{
    pthread_descr self = thread_self();

    return (asctime_r(timeptr, self->time_buf));
}

char * ctime(const time_t * const timep)
{
    pthread_descr self = thread_self();

    return (ctime_r(timep, self->time_buf));
}


struct tm *localtime (const time_t * const timep)
{
    pthread_descr self = thread_self();

    return (localtime_r(timep, &self->local_tm));
}

struct tm * gmtime(const time_t * const	timep)
{
    pthread_descr self = thread_self();

    return (gmtime_r(timep, &self->local_tm));
}
#endif

/* The following wrappers impement cancallation points */


#if __STDC__
int msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg)
#else
int msgrcv(msqid, msgp, msgsz, msgtyp, msgflg)
	int msqid;
	void *msgp;
	size_t msgsz;
	long msgtyp;
	int msgflg;
#endif
{
        int ret;
	int oldtype;

	/* This is a cancellation point */
	pthread_setcanceltype (PTHREAD_CANCEL_ASYNCHRONOUS, &oldtype);

	ret = msgsys(3, msqid, msgp, msgsz, msgtyp, msgflg);

	/* This is a cancellation point */
	pthread_setcanceltype  (oldtype, NULL);
	return (ret);

}

#if __STDC__
#if __FreeBSD_version > 500100
int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg)
#else
int msgsnd(int msqid, void *msgp, size_t msgsz, int msgflg)
#endif
#else
int msgsnd(msqid, msgp, msgsz, msgflg)
	int msqid;
#if __FreeBSD_version > 500100
	const void *msgp;
#else
	void *msgp;
#endif
	size_t msgsz;
	int msgflg;
#endif
{
        int ret;
	int oldtype;

	/* This is a cancellation point */
	pthread_setcanceltype (PTHREAD_CANCEL_ASYNCHRONOUS, &oldtype);

	ret = msgsys(2, msqid, msgp, msgsz, msgflg);

	/* This is a cancellation point */
	pthread_setcanceltype  (oldtype, NULL);
	return (ret);

}

#if __STDC__
int tcdrain (int fd)
#else
int tcdrain (fd)
        int fd;
#endif
{
        int ret;
	int oldtype;

	/* This is a cancellation point */
	pthread_setcanceltype (PTHREAD_CANCEL_ASYNCHRONOUS, &oldtype);

	ret = ioctl(fd, TIOCDRAIN, 0);

	/* This is a cancellation point */
	pthread_setcanceltype  (oldtype, NULL);
	return (ret);
}

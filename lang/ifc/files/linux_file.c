/*
 * Copyright (c) 2002  The FreeBSD Project
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
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

#define	LINUX_O_RDONLY		00
#define	LINUX_O_WRONLY		01
#define	LINUX_O_RDWR		02
#define	LINUX_O_CREAT		0100
#define	LINUX_O_EXCL		0200
#define	LINUX_O_NOCTTY		0400
#define	LINUX_O_TRUNC		01000
#define	LINUX_O_APPEND		02000
#define	LINUX_O_NONBLOCK	04000
#define	LINUX_O_NDELAY		LINUX_O_NONBLOCK
#define	LINUX_O_SYNC		010000
#define LINUX_FASYNC            020000

int l_open(const char *path, int flags, ...) {
    va_list args;
    mode_t mode;
    int bsd_flags, error;
    bsd_flags = 0;

    if (flags & LINUX_O_RDONLY  ) bsd_flags |= O_RDONLY;
    if (flags & LINUX_O_WRONLY  ) bsd_flags |= O_WRONLY;
    if (flags & LINUX_O_RDWR    ) bsd_flags |= O_RDWR;
    if (flags & LINUX_O_NDELAY  ) bsd_flags |= O_NONBLOCK;
    if (flags & LINUX_O_APPEND  ) bsd_flags |= O_APPEND;
    if (flags & LINUX_O_SYNC    ) bsd_flags |= O_FSYNC;
    if (flags & LINUX_O_NONBLOCK) bsd_flags |= O_NONBLOCK;
    if (flags & LINUX_FASYNC    ) bsd_flags |= O_ASYNC;
    if (flags & LINUX_O_CREAT   ) bsd_flags |= O_CREAT;
    if (flags & LINUX_O_TRUNC   ) bsd_flags |= O_TRUNC;
    if (flags & LINUX_O_EXCL    ) bsd_flags |= O_EXCL;
    if (flags & LINUX_O_NOCTTY  ) bsd_flags |= O_NOCTTY;

    if (bsd_flags & O_CREAT) {
	va_start (args, flags);
	mode = (mode_t) va_arg(args, int);
	return open(path, bsd_flags, mode);
	va_end (args);
    } else
	return open(path, bsd_flags);
}

int open64(const char *path, int flags, ...) {
    va_list args;
    mode_t mode;
    int bsd_flags, error;
    bsd_flags = 0;

    if (flags & LINUX_O_RDONLY  ) bsd_flags |= O_RDONLY;
    if (flags & LINUX_O_WRONLY  ) bsd_flags |= O_WRONLY;
    if (flags & LINUX_O_RDWR    ) bsd_flags |= O_RDWR;
    if (flags & LINUX_O_NDELAY  ) bsd_flags |= O_NONBLOCK;
    if (flags & LINUX_O_APPEND  ) bsd_flags |= O_APPEND;
    if (flags & LINUX_O_SYNC    ) bsd_flags |= O_FSYNC;
    if (flags & LINUX_O_NONBLOCK) bsd_flags |= O_NONBLOCK;
    if (flags & LINUX_FASYNC    ) bsd_flags |= O_ASYNC;
    if (flags & LINUX_O_CREAT   ) bsd_flags |= O_CREAT;
    if (flags & LINUX_O_TRUNC   ) bsd_flags |= O_TRUNC;
    if (flags & LINUX_O_EXCL    ) bsd_flags |= O_EXCL;
    if (flags & LINUX_O_NOCTTY  ) bsd_flags |= O_NOCTTY;

    if (bsd_flags & O_CREAT) {
	va_start (args, flags);
	mode = (mode_t) va_arg(args, int);
	return open(path, bsd_flags, mode);
	va_end (args);
    } else
	return open(path, bsd_flags);
}

typedef int32_t         l_long;
typedef l_long          l_off_t;

l_off_t l_lseek(int fildes, l_off_t offset, int whence)
{
    return (l_off_t) lseek(fildes, (off_t) offset, whence);
}

int l_ftruncate(int fildes, l_off_t length)
{
    return ftruncate(fildes, (off_t) length);
}

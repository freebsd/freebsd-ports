/*
 * Copyright (c) 2003  The FreeBSD Project
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

#include <sys/types.h>
#include <sys/mman.h>

typedef int32_t         l_long;
typedef unsigned int    l_uint;
typedef l_long          l_off_t;
typedef l_uint          l_size_t;

/* mmap options */
#define LINUX_MAP_SHARED        0x0001
#define LINUX_MAP_PRIVATE       0x0002
#define LINUX_MAP_FIXED         0x0010
#define LINUX_MAP_ANON          0x0020
#define LINUX_MAP_GROWSDOWN     0x0100

void *
Mmap(void *addr, l_size_t len, int prot, int flags, int fd, l_off_t offset)
{
    int bsd_flags = 0;

    if (flags & LINUX_MAP_SHARED )   bsd_flags |= MAP_SHARED;
    if (flags & LINUX_MAP_PRIVATE)   bsd_flags |= MAP_PRIVATE;
    if (flags & LINUX_MAP_FIXED  )   bsd_flags |= MAP_FIXED;
    if (flags & LINUX_MAP_ANON   )   bsd_flags |= MAP_ANON;
    else                             bsd_flags |= MAP_NOSYNC;
    if (flags & LINUX_MAP_GROWSDOWN) bsd_flags |= MAP_STACK;

    prot |= PROT_READ;	/* always required */
    if (flags & LINUX_MAP_ANON)
	fd = -1;

    return mmap(addr, (size_t) len, prot, bsd_flags, fd, (off_t) offset);
}

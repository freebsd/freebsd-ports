/*
 * Copyright (c) 1999 Richard Seaman, Jr.
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

#include <dlfcn.h>
#include <stdlib.h>
#include "pthread.h"
/* Our internal pthreads definitions are here. Set as needed */
#if defined(COMPILING_UTHREADS)
#include "pthread_private.h"
#endif
#if defined(LINUXTHREADS)
#include <errno.h>
#include "internals.h"
#include "spinlock.h"
#else
/* Your internal definition here */
#endif

/* These are from lib/libc/include */
#if !defined(LINUXTHREADS)
#include "spinlock.h"
#endif

/* This is defined in lib/libc/stdlib/exit.c.  It turns on thread safe
 * behavior in libc if non-zero.
 */
extern int __isthreaded;

/* Optional.  In case our code is dependant on the existence of
 * the posix priority extentions kernel option.
 */
#if defined(LINUXTHREADS)
#include <sys/sysctl.h>
int _posix_priority_scheduling;
#endif

void *lock_create (void *context);
void rlock_acquire (void *lock);
void wlock_acquire (void *lock);
void lock_release (void *lock);
void lock_destroy (void *lock);


/* Use the constructor attribute so this gets run before main does */
static void _pthread_initialize(void) __attribute__((constructor));

static void _pthread_initialize(void)
{

#if defined(LINUXTHREADS)
#if !defined(LINUXTHREADS_NO_POSIX_PRIORITY_SCHEDULING)
	int mib[2];
	size_t len;

	len = sizeof (_posix_priority_scheduling);
	mib[0] = CTL_P1003_1B;
	mib[1] = CTL_P1003_1B_PRIORITY_SCHEDULING;
	if (-1 == sysctl (mib, 2, &_posix_priority_scheduling, &len, NULL, 0))
		_posix_priority_scheduling = 0;
#endif
#endif

	/* This turns on thread safe behaviour in libc when we link with it */
	__isthreaded = 1;

}

void _spinlock (int * spinlock)
{
	__pthread_acquire(spinlock);
}


void _spinunlock(int *spinlock)
{
	*spinlock = 0;
}

void * lock_create (void *context)
{
	pthread_rwlock_t *lock;

	lock = malloc (sizeof (*lock));
	if (lock == NULL)
		return (NULL);

	pthread_rwlock_init (lock, NULL);
	return (lock);
}

void rlock_acquire (void *lock)
{
	pthread_rwlock_rdlock ((pthread_rwlock_t *)lock);

}

void wlock_acquire (void *lock)
{
	pthread_rwlock_wrlock ((pthread_rwlock_t *)lock);

}

void lock_release (void *lock)
{
	pthread_rwlock_unlock ((pthread_rwlock_t *)lock);
}

void lock_destroy (void *lock)
{
	if (pthread_rwlock_destroy ((pthread_rwlock_t *)lock) == 0)
		free (lock);
}

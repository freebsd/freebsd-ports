/* Based on code marked: */

/*-
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
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
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
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
 * from: FreeBSD: src/lib/libc/stdlib/atexit.c,v 1.7 2003/12/19 17:11:20 kan Exp
 *
 */

/*
 * Copyright (c) 2004 Marius Strobl <marius@alchemy.franken.de>.
 * All rights reserved.
 *
 * The same license as above applies. If clause 3 of the license in the
 * above mentioned file gets removed this file should follow and this
 * sentence should get removed.
 *
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: /tmp/pcvs/ports/lang/ifc/files/cxa_atexit.c,v 1.3 2004-01-31 23:32:41 maho Exp $");

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <osreldate.h>

#if __FreeBSD_version >= 502101
	#error "Not required on this version of FreeBSD."
#endif

#define	ATEXIT_FN_EMPTY	0
#define	ATEXIT_FN_STD	1
#define	ATEXIT_FN_CXA	2

/* must be at least 32 to guarantee ANSI conformance */
#define	ATEXIT_SIZE	32

extern int __isthreaded;

#if __FreeBSD_version < 500016
typedef struct {
	volatile long	access_lock;
	volatile long	lock_owner;
	volatile char	*fname;
	volatile int	lineno;
} spinlock_t;

#define	_SPINLOCK_INITIALIZER	{ 0, 0, 0, 0 }

#define	_SPINUNLOCK(_lck)	(_lck)->access_lock = 0
#ifdef	_LOCK_DEBUG
#define	_SPINLOCK(_lck)		_spinlock_debug(_lck, __FILE__, __LINE__)
#else
#define	_SPINLOCK(_lck)		_spinlock(_lck)
#endif

static spinlock_t thread_lock = _SPINLOCK_INITIALIZER;

#define _ATEXIT_LOCK()		if (__isthreaded) _SPINLOCK(&thread_lock);
#define _ATEXIT_UNLOCK()	if (__isthreaded) _SPINUNLOCK(&thread_lock);
#else
#include <pthread.h>

static pthread_mutex_t atexit_mutex = PTHREAD_MUTEX_INITIALIZER;

#define _ATEXIT_LOCK()		if (__isthreaded) \
				_pthread_mutex_lock(&atexit_mutex)
#define _ATEXIT_UNLOCK()	if (__isthreaded) \
				_pthread_mutex_unlock(&atexit_mutex)
#endif

struct atexit {
	struct atexit *next;			/* next in list */
	int ind;				/* next index in this table */
	struct atexit_fn {
		int fn_type;			/* ATEXIT_? from above */
		union {
			void (*std_func)(void);
			void (*cxa_func)(void *);
		} fn_ptr;			/* function pointer */
		void *fn_arg;			/* argument for CXA callback */
		void *fn_dso;			/* shared module handle */
	} fns[ATEXIT_SIZE];			/* the table itself */
};

static struct atexit *__atexit;		/* points to head of LIFO stack */

/*
 * Register the function described by 'fptr' to be called at application
 * exit or owning shared object unload time. This is a helper function
 * for atexit and __cxa_atexit.
 */
static int
atexit_register(struct atexit_fn *fptr)
{
	static struct atexit __atexit0;	/* one guaranteed table */
	struct atexit *p;

	_ATEXIT_LOCK();
	if ((p = __atexit) == NULL)
		__atexit = p = &__atexit0;
	else while (p->ind >= ATEXIT_SIZE) {
		struct atexit *old__atexit;
		old__atexit = __atexit;
	        _ATEXIT_UNLOCK();
		if ((p = (struct atexit *)malloc(sizeof(*p))) == NULL)
			return (-1);
		_ATEXIT_LOCK();
		if (old__atexit != __atexit) {
			/* Lost race, retry operation */
			_ATEXIT_UNLOCK();
			free(p);
			_ATEXIT_LOCK();
			p = __atexit;
			continue;
		}
		p->ind = 0;
		p->next = __atexit;
		__atexit = p;
	}
	p->fns[p->ind++] = *fptr;
	_ATEXIT_UNLOCK();
	return 0;
}

/*
 * Register a function to be performed at exit or when an shared object
 * with given dso handle is unloaded dynamically.
 */
int
__cxa_atexit(void (*func)(void *), void *arg, void *dso)
{
	struct atexit_fn fn;
	int error;

	fn.fn_type = ATEXIT_FN_CXA;
	fn.fn_ptr.cxa_func = func;;
	fn.fn_arg = arg;
	fn.fn_dso = dso;

 	error = atexit_register(&fn);	
	return (error);
}

/*
 * Call all handlers registered with __cxa_atexit for the shared
 * object owning 'dso'.  Note: if 'dso' is NULL, then all remaining
 * handlers are called.
 */
void
__cxa_finalize(void *dso)
{
	struct atexit *p;
	struct atexit_fn fn;
	int n;

	_ATEXIT_LOCK();
	for (p = __atexit; p; p = p->next) {
		for (n = p->ind; --n >= 0;) {
			if (p->fns[n].fn_type == ATEXIT_FN_EMPTY)
				continue; /* already been called */
			if (dso != NULL && dso != p->fns[n].fn_dso)
				continue; /* wrong DSO */
			fn = p->fns[n];
			/*
			  Mark entry to indicate that this particular handler
			  has already been called.
			*/
			p->fns[n].fn_type = ATEXIT_FN_EMPTY;
		        _ATEXIT_UNLOCK();
		
			/* Call the function of correct type. */
			if (fn.fn_type == ATEXIT_FN_CXA)
				fn.fn_ptr.cxa_func(fn.fn_arg);
			else if (fn.fn_type == ATEXIT_FN_STD)
				fn.fn_ptr.std_func();
			_ATEXIT_LOCK();
		}
	}
	_ATEXIT_UNLOCK();
}

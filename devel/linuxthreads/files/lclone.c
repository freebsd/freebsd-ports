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


#include <sys/types.h>
#include <sys/signal.h>
#include <sys/unistd.h>
#include <errno.h>
#include <clone.h>

int clone (int (*__fn) (void *), void *__child_stack,
	   int __flags, void *__arg) __attribute__ ((weak, alias("__clone")));

extern int __clone (int (*__fn) (void *), void *__child_stack,
			 int __flags, void *__arg)
{
	int bsd_flags;
	int exit_signal;

	/* We don't have qn equivalent to CLONE_PID yet */
	if (__flags & CLONE_PID)
		return (-1);

	if (__child_stack == (void *)0)
		return (-1);

	/* RFTHREAD probably not necessary here, but it shouldn't hurt either */
	bsd_flags = RFPROC | RFTHREAD;

	/* We only allow one alternative to SIGCHLD, and thats
	 * SIGUSR1.  This is less flexible than Linux, but
	 * we don't really have a way to pass a one byte
	 * exit signal to rfork, which is what Linux passes to
	 * its clone syscall.  OTOH, we haven't seen Linux use
	 * a value other than 0 (which implies SIGCHLD), SIGCHLD,
	 * or SIGUSER1 so far.
	 */
	exit_signal = ((unsigned int)__flags) & CSIGNAL;
	switch (exit_signal){
	case 0:
	case SIGCHLD:
		/* SIGCHLD is the default for BSD, so we don't have
		 * to do anything special in this case.
		 */
		break;
	case SIGUSR1:
		bsd_flags |= RFLINUXTHPN;
		break;
	default:
		return (-1);
	}

	if (__flags & CLONE_VM)
		bsd_flags |= RFMEM;
	if (__flags & CLONE_SIGHAND)
		bsd_flags |= RFSIGSHARE;
	if (!(__flags & CLONE_FILES))
		bsd_flags |= RFFDG;

	/* _clone is in clone.S, and takes bsd style rfork flags */
	return (_clone (__fn, __child_stack, bsd_flags,  __arg));
}

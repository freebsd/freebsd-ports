/*
 * Copyright (c) 2002 Marius Strobl
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
 * $FreeBSD: /tmp/pcvs/ports/lang/ifc/files/cxa_atexit.c,v 1.1 2002-11-18 09:27:32 maho Exp $
 */

#include <stdlib.h>

/*
 * The __cxa_atexit() function and friends are needed for full (IA64) C++ ABI
 * compatibility but FreeBSD doesn't have implemented them, yet. In addition
 * to the classic atexit() it is not only used to register functions to be
 * called at program exit but also to call them (C++ destructors in that case)
 * when a shared object is unloaded. For the later to work the dynamic linker
 * assigns a unique dynamic shared object handle to every shared object while
 * a handle of NULL represents a main program. When __cxa_finalize() is called
 * with a specific (non-NULL) handle as an argument all functions registered
 * via __cxa_atexit() and having the same handle are called.
 * The best we can do here to emulate that behaviour until FreeBSD supports
 * this is to register the functions via atexit(). While this certainly is a
 * bad hack it seems to work, even the current dynamic linker is assigning
 * the handles. I didn't see a function getting registered with an argument
 * so far.
 */
int
__cxa_atexit(void (*fn)(), void *arg, void *handle)
{

	return (handle ? atexit(fn) : 0);
}

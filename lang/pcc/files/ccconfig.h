/* $FreeBSD$ */
/*	$Id: ccconfig.h,v 1.2 2004/12/02 21:32:25 ragge Exp $	*/

/*
 * Copyright (c) 2007 David O'Brien
 * Copyright (c) 2004 Anders Magnusson (ragge@ludd.luth.se).
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
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Various settings that controls how the C compiler works.
 */

/* common cpp predefines */
#define CPPADD	{ "-D__FreeBSD__=%%OSVERMAJOR%%", "-D__ELF__", "-D__unix__=1", "-D__unix=1", "-D__STDC__=1", NULL, }
#define DYNLINKER { "-dynamic-linker", "/libexec/ld-elf.so.1", NULL }
#define CRT0FILE "/usr/lib/crt1.o"
#define STARTFILES { "/usr/lib/crti.o", "/usr/lib/crtbegin.o", NULL }
#define	ENDFILES { "/usr/lib/crtend.o", "/usr/lib/crtn.o", NULL }
#define STARTLABEL "_start"

/*
 * XXX multitargets ?
 */
#if defined(mach_i386) || defined(mach_x86)
#define	CPPMDADD { "-D__i386__", "-D__i386", NULL, }
#elif defined(mach_amd64)
#define CPPMDADD { "-D__x86_64__", NULL, }
#else
#error defines for arch missing
#endif

#define	STABS

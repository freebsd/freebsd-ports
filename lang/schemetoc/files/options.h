/* SCHEME->C */

/*           Copyright 1989-1993 Digital Equipment Corporation
 *                         All Rights Reserved
 *
 * Permission to use, copy, and modify this software and its documentation is
 * hereby granted only under the following terms and conditions.  Both the
 * above copyright notice and this permission notice must appear in all copies
 * of the software, derivative works or modified versions, and any portions
 * thereof, and both notices must appear in supporting documentation.
 *
 * Users of this software agree to the terms and conditions set forth herein,
 * and hereby grant back to Digital a non-exclusive, unrestricted, royalty-free
 * right and license under any changes, enhancements or extensions made to the
 * core functions of the software, including but not limited to those affording
 * compatibility with other hardware or software environments, but excluding
 * applications which incorporate this software.  Users further agree to use
 * their best efforts to return to Digital any such changes, enhancements or
 * extensions that they make and inform Digital of noteworthy uses of this
 * software.  Correspondence should be provided to Digital at:
 * 
 *                       Director of Licensing
 *                       Western Research Laboratory
 *                       Digital Equipment Corporation
 *                       250 University Avenue
 *                       Palo Alto, California  94301  
 * 
 * This software may be distributed (but not offered for sale or transferred
 * for compensation) to third parties, provided such third parties agree to
 * abide by the terms and conditions of this notice.  
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT
 * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
*/

/* This file defines compilation options for a specific implementation */

#define CHECKSTACK	1	/* 0 = don't check stack height */
				/* 1 = check stack height */

#define TIMESLICE	0	/* 0 = don't time slice execution */
				/* 1 = time slice execution */

#define COMPACTPUSHTRACE 0	/* 0 = inline procedure entry checks.
				   1 = emit procedure call for procedure
				       entry checks.
				*/

#define COMPACTPOPTRACE 0	/* 0 = inline procedure exit cleanup.
				   1 = emit procedure call for procedure exit
				       cleanup.
				*/

#define S2CSIGNALS	1	/* 0 = Scheme->C doesn't handle signals */
				/* 1 = Scheme->C does handle signals */

#define	MATHTRAPS	0	/* 0 = don't detect fixed point overflow */
				/* 1 = recover on fixed point overflow */

/* Define only one of the supported processor types:

	AOSF		Alpha AXP OSF/1
	HP700		HP 9000/700
	MAC		Macintosh system 7.1 with Think-C 5.0
	MC680X0		HP 9000/300, Sun 3, Next
	MIPS		DECstation, SGI, Sony News
	VAX		Vax ULTRIX
	FREEBSD		x86 FreeBSD
	WIN16		Microsoft Windows 3.1
*/

#define FREEBSD 1

/* Attributes of the selected architecture:

   The following four macros define specific aspects of the system.  They
   are defined as strings, or specifically undefined:

	IMPLEMENTATION_MACHINE	machine type
	IMPLEMENTATION_CPU	cpu type
	IMPLEMENTATION_OS	operating system
	IMPLEMENTATION_FS	file system

   Big endian vs. little endian:

	BIGENDIAN		defined to 1 to denote bigendian systems

   C compiler:

	OLD_FASHIONED_C		defined to 1 for pre-ANSI compilers

   Alignment:

	DOUBLE_ALIGN		defined to 1 to force doubles to be aligned on
				an even S2CINT boundary

   Macro expansion:

	NEED_MACRO_ARGS		defined to 1 to declare a macro like X() as
				X(dummy)

   The types S2CINT and S2CUINT are defined to be signed and unsigned integers
   that are the same size as pointers.  This is the basic "word" used by
   Scheme->C.

   The machine state when a continuation is created is captured in the
   sc_jmp_buf data structure.

   STACKPTR( x ) is a define that stores the address of the stack pointer
   in x.

   Unix flavors:

	POSIX			POSIX.1 compliant
	SYSV			System V or derivative
	SYSV4			System V release 4 (also define SYSV, POSIX)
*/

/**************/
/*    AOSF    */
/**************/

#ifdef AOSF
#define IMPLEMENTATION_MACHINE	"Alpha AXP"
#undef  IMPLEMENTATION_CPU	
#define IMPLEMENTATION_OS	"OSF/1"
#undef  IMPLEMENTATION_FS

typedef long int S2CINT;		/* Signed pointer size integer */
typedef long unsigned S2CUINT;		/* Unsigned pointer size interger */

typedef int PAGELINK;			/* 32-bit sc_pagelink values */
#define MAXS2CINT  0x7fffffffffffffffL	/* Maximum value of an S2CINT */
#define MSBS2CUINT 0x8000000000000000L	/* S2CUINT with 1 in the MSB */

typedef long int sc_jmp_buf[ 9 ]; /* The buffer contains the following items:
				     s0-s6	saved registers
				     ra		return address
				     sp	        stack pointer
				  */

#define STACKPTR( x ) x = sc_getsp()
extern  S2CINT*  sc_getsp();

#define NEED_MACRO_ARGS 1
#endif

/***************/
/*    HP700    */
/***************/

#ifdef HP700

#ifdef __hp9000s700
#define IMPLEMENTATION_MACHINE	"HP9000/700"
#else
#ifdef __hp9000s800
#define IMPLEMENTATION_MACHINE	"HP9000/800"
#endif
#endif

#define IMPLEMENTATION_CPU	"HP-PA"

#define BIGENDIAN 1

#define DOUBLE_ALIGN 1

typedef int S2CINT;			/* Signed pointer size integer */
typedef unsigned S2CUINT;		/* Unsigned pointer size interger */

typedef int PAGELINK;			/* 32-bit sc_pagelink values */
#define MAXS2CINT  0x7fffffff		/* Maximum value of an S2CINT */
#define MSBS2CUINT 0x80000000		/* S2CUINT with 1 in the MSB */

#define STACKPTR(x) ((x) = (sc_processor_register (30)))

#define STACK_GROWS_POSITIVE 1

#endif

#ifdef __hpux
#define IMPLEMENTATION_OS	"HP-UX"
#undef  IMPLEMENTATION_FS

#ifdef __STDC__
#undef OLD_FASHIONED_C
#else
#define OLD_FASHIONED_C 1
#endif

#include <setjmp.h>
typedef jmp_buf sc_jmp_buf;

#define SYSV 1
#define POSIX 1

#endif

/*************/
/*    MAC    */
/*************/

#ifdef MAC
#define IMPLEMENTATION_MACHINE	"Apple Macintosh"
#define IMPLEMENTATION_CPU	"680x0"
#define IMPLEMENTATION_OS	"7.1"
#undef  IMPLEMENTATION_FS

#define BIGENDIAN 1

typedef long int S2CINT;		/* Signed pointer size integer */
typedef long unsigned S2CUINT;		/* Unsigned pointer size interger */

typedef short int PAGELINK;		/* 16-bit sc_pagelink values */
#define MAXS2CINT  0x7fffffffL		/* Maximum value of an S2CINT */
#define MSBS2CUINT 0x80000000L		/* S2CUINT with 1 in the MSB */

#include <setjmp.h>
typedef jmp_buf sc_jmp_buf;
#undef TRUE
#undef FALSE

#define STACKPTR( x ) x = sc_getsp()
extern  S2CINT*  sc_getsp();

#define SCHEAP 1
#define SCMAXHEAP 15
#endif

/****************/
/*   MC680X0    */
/****************/ 

#ifdef MC680X0
#define IMPLEMENTATION_CPU	"680x0"

#define BIGENDIAN 1

typedef int S2CINT;			/* Signed pointer size integer */
typedef unsigned S2CUINT;		/* Unsigned pointer size interger */

typedef int PAGELINK;			/* 32-bit sc_pagelink values */
#define MAXS2CINT  0x7fffffff		/* Maximum value of an S2CINT */
#define MSBS2CUINT 0x80000000		/* S2CUINT with 1 in the MSB */

#define STACKPTR(x) ((x) = (sc_processor_register (15)))

#ifdef __hp9000s400
#define IMPLEMENTATION_MACHINE	"HP9000/400"
#else
#ifdef __hp9000s300
#define IMPLEMENTATION_MACHINE	"HP9000/300"
#endif
#endif

/* HP-UX dependent conditionalizations performed above.  */

#endif

/**************/
/*    MIPS    */
/**************/

#ifdef MIPS
#define IMPLEMENTATION_MACHINE	"DECstation"
#define IMPLEMENTATION_CPU	"Rx000"
#define IMPLEMENTATION_OS	"ULTRIX"
#undef  IMPLEMENTATION_FS

#define DOUBLE_ALIGN 1

typedef int S2CINT;			/* Signed pointer size integer */
typedef unsigned S2CUINT;		/* Unsigned pointer size interger */

typedef int PAGELINK;			/* 32-bit sc_pagelink values */
#define MAXS2CINT  0x7fffffff		/* Maximum value of an S2CINT */
#define MSBS2CUINT 0x80000000		/* S2CUINT with 1 in the MSB */

#ifndef MIPSEL
#define BIGMIPS 1
#define BIGENDIAN 1
#undef  IMPLEMENTATION_MACHINE
#define IMPLEMENTATION_MACHINE	"Big Endian MIPS"
#undef  IMPLEMENTATION_OS

/* Not sure what the correct conditionalization is here -- NEWS-OS
   5.xx defines both "sony" and "sonyrisc", but apparently NEWS-OS
   4.xx defines "sony_mips", because the previous version of Scheme->C
   was conditionalized on "sony_mips" which is *not* defined by
   NEWS-OS 5.xx.  If there's an intersection between the symbols
   defined by 4.xx and 5.xx then a member of that intersection should
   be used for the conditionalization; otherwise test for both.
*/
#ifdef sonyrisc

#undef  IMPLEMENTATION_MACHINE
#define IMPLEMENTATION_MACHINE	"Sony MIPS"
#undef  IMPLEMENTATION_CPU
#define IMPLEMENTATION_CPU	"R3000"
#undef  IMPLEMENTATION_OS
#define IMPLEMENTATION_OS	"NEWS-OS"

#ifdef SYSTYPE_SYSV

#define SYSV4 1
#define SYSV 1
#define POSIX 1

/* This can be implemented but requires generalizing the signal
   handler to know about SYSV4 siginfo structure.
*/

#undef  MATHTRAPS
#define MATHTRAPS 0

#define NEED_MACRO_ARGS 1

#define COPY_STACK_BEFORE_LONGJMP 1

#endif
#endif
#endif

#include <setjmp.h>
typedef jmp_buf sc_jmp_buf;

#define STACKPTR( x ) x = sc_processor_register( 29 )
#endif

/*************/
/*    VAX    */
/*************/

#ifdef VAX
#define IMPLEMENTATION_MACHINE	"VAX"
#undef  IMPLEMENTATION_CPU
#define IMPLEMENTATION_OS	"ULTRIX"
#undef  IMPLEMENTATION_FS

#define OLD_FASHIONED_C 1

typedef int S2CINT;			/* Signed pointer size integer */
typedef unsigned S2CUINT;		/* Unsigned pointer size interger */

typedef int PAGELINK;			/* 32-bit sc_pagelink values */
#define MAXS2CINT  0x7fffffff		/* Maximum value of an S2CINT */
#define MSBS2CUINT 0x80000000		/* S2CUINT with 1 in the MSB */

typedef int sc_jmp_buf[ 16 ];	/* The buffer contains the following items:
				   R2-R11	saved registers
				   SIGM		saved signal mask
				   SP		stack pointer on entry to
				   		setjmp
				   PSW		PSW word from stack frame
				   AP		saved argument ptr from frame
				   FP		saved frame ptr from frame
				   PC		saved program cntr from frame
				*/

#define STACKPTR( x ) x = sc_processor_register( 14 )
#endif

/***************/
/*   FREEBSD   */
/***************/

#ifdef FREEBSD
#define IMPLEMENTATION_MACHINE	"Generic PC"
#define IMPLEMENTATION_CPU	"Intelx86"
#define IMPLEMENTATION_OS	"FreeBSD"
#undef  IMPLEMENTATION_FS

typedef int S2CINT;		/* Signed pointer size integer */
typedef unsigned S2CUINT;	/* Unsigned pointer size interger */

typedef int PAGELINK;		/* 32-bit sc_pagelink values */
#define MAXS2CINT  0x7fffffff	/* Maximum value of an S2CINT */
#define MSBS2CUINT 0x80000000	/* S2CUINT with 1 in the MSB */

#define STACKPTR( x ) x = sc_processor_register( 0 )

#include <setjmp.h>
typedef jmp_buf sc_jmp_buf;

/* Horrid kludge.  See callcc.c for the full story: */
#define LAZY_STACK_POP 1
#define LAZY_STACK_INCREMENT 4

#endif

/***************/
/*    WIN16    */
/***************/

#ifdef WIN16
#define IMPLEMENTATION_MACHINE	"Generic PC"
#define IMPLEMENTATION_CPU	"Intelx86"
#define IMPLEMENTATION_OS	"Microsoft Windows 3.1"
#undef  IMPLEMENTATION_FS

typedef long int S2CINT;		/* Signed pointer size integer */
typedef long unsigned S2CUINT;		/* Unsigned pointer size interger */

typedef short int PAGELINK;		/* 16-bit sc_pagelink values */
#define MAXS2CINT  0x7fffffffL		/* Maximum value of an S2CINT */
#define MSBS2CUINT 0x80000000L		/* S2CUINT with 1 in the MSB */

#include <windows.h>
#undef TRUE
#undef FALSE
typedef CATCHBUF sc_jmp_buf;

#define STACKPTR( x ) x = sc_processor_register( 0 )

#define MAXSTRINGSIZE	       ((S2CINT)65532)
#define MAXVECTORSIZE	       ((S2CINT)16383)

#define SCHEAP 2
#define SCMAXHEAP 15
#endif

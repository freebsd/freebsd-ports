/*
 * *****************************************************************
 * *                                                               *
 * *    Copyright (c) Compaq Computer Corporation, 1991, 1999      *
 * *                                                               *
 * *   All Rights Reserved.  Unpublished rights  reserved  under   *
 * *   the copyright laws of the United States.                    *
 * *                                                               *
 * *   The software contained on this media  is  proprietary  to   *
 * *   and  embodies  the  confidential  technology  of  Compaq    *
 * *   Computer  Corporation.  Possession, use,  duplication  or   *
 * *   dissemination of the software and media is authorized only  *
 * *   pursuant to a valid written license from Compaq Computer    *
 * *   Corporation.                                                *
 * *                                                               *
 * *   RESTRICTED RIGHTS LEGEND   Use, duplication, or disclosure  *
 * *   by the U.S. Government is subject to restrictions  as  set  *
 * *   forth in Subparagraph (c)(1)(ii)  of  DFARS  252.227-7013,  *
 * *   or  in  FAR 52.227-19, as applicable.                       *
 * *                                                               *
 * *****************************************************************
 */
/*
 * HISTORY
 */
/*
 * @(#)$RCSfile: c_asm.h,v $ $Revision: 1.1.8.3 $ (DEC) $Date: 1996/01/11 20:56:45 $
 */
#ifndef __C_ASM_H
#define __C_ASM_H
#ifdef __cplusplus
extern "C" {
#endif

/*** #include <c_asm.h>
 *
 *   Synopsis:  This header file is used to control the functionality
 *              of the asm in-line assembly language generator
 *              functions.  Users include this header file to get
 *              the special compiler-defined behavior.  Not defining
 *              it causes asm and friends to default to normal function
 *              call behavior.
 *
 *** Usage information:
 *
 *   asm, dasm, and fasm all have function semantics in terms of how
 *   they are viewed by the compiler.  The following restrictions apply:
 *
 *   1.  The first parameter must be a constant character string
 *       (that is, it may not be a complex reference into a table,
 *       and it may not be something which requires runtime evaluation.
 *
 *   2.  asm returns integral values, fasm returns floating values,
 *       and dasm returns double values.  It is the responsibility
 *       of the user to insure that the result value is placed into
 *       the proper return register (that is, v0 for asm, f0 for
 *       fasm/dasm).
 *
 *   3.  A return value is optional; that is, backward compatibility
 *       with the "old" asm is maintained.asm, dasm, or fasm can be seen as
 *       void functions at the user's option.
 *
 *
  *** Usage Examples:
 *
 *   1. In this example, asms are used to execute a particular
 *      machine instruction and return a value.  Note that the
 *      second asm must also be expressed with arguments to load
 *      a0 and a1.  There are no guarantees that the values in
 *      a0 and a1 are preserved from the first to the second
 *      asm, or even that the compiler chose to use a0 and a1
 *      (it could have "inlined" the asm).  Similarly, there must
 *      be an explicit return of the value of the second asm.
 *      Putting a value in %v0 is not sufficient to return a
 *      value from domath.
 *
 *   #include <c_asm.h>
 *
 *   long domath(pl)
 *       long *pl;
 *   {
 *       long op1, op2;
 *
 *       op1  = 0xffffffffffffffff;
 *       op2  = 0xfff;
 *
 *       *pl = asm("umulh %a0, %a1, %v0", op1, op2);
 *       return asm("mulq  %a0, %a1, %v0", op1, op2);
 *
 *   }
 *
 *   main()
 *   {
 *       long results[2];
 *
 *       results[1] = domath(results);
 *
 *       printf("%d %d\n", results[0], results[1]);
 *   }
* *
 *
 *   2. In this example we have an asm used to call PAL calls.
 *      Note the use of C preprocessor capabilities to allow
 *      substitutions within the asm string, which must be a
 *      compile-time string constant:
 *
 *   #include <c_asm.h>
 *   #include <machine/pal.h>
 *
 *   #define QUOTE(s) #s
 *   #define STR(s) QUOTE(s)
 *   #define WRUNIQ(uniq) asm("call_pal " STR(PAL_wruniq), (uniq))
 *   #define RDUNIQ() asm("call_pal " STR(PAL_rduniq))
 *
 *   main()
 *       {
 *       int i = 123456;
 *       int j;
 *
 *	  WRUNIQ(i);
 *
 *	  j = RDUNIQ();
 *
 *	  printf("i=%d; j=%d\n", i, j);
 *	 }
 *
 *   3. In this example we have an asm used to perform a locking
 *      primitive.  This asm contains labels and branches.  All labels
 *      and branches must be in the same
 *
 *      Note that the DEC C _TESTBITSSI builtin function gives similar
 *	functionality, and may produce a slightly better code sequence
 *	in some cases.**
 *
 *   #include <c_asm.h>
 *   #include <stdio.h>
 *
 *   # define pthread_mutex_lock_prim(_m_) asm (" \
 *           ldah    %t2,0x10(%r31) ;\
 *       10: ldl_l   %v0,(%a0) ;\
 *           bne     %v0,30f ;\
 *           or      %v0,%t2,%t0 ;\
 *           stl_c   %t0,(%a0) ;\
 *           beq     %t0,20f ;\
 *           mb      ; \
 *           br      %r31,30f ;\
 *       20: br      %r31,10b ;\
 *       30:", (_m_))
 *
 *   int main () {
 *       unsigned int        lock = 0;
 *       pthread_mutex_lock_prim (&lock);
 *       printf ("lock is %#x\n", lock);
 *       return 0;
 *       }
 *
 *   4. In this example we have the one supported violation
 *      of function call semantics for asms -- using an asm
 *      to get the return address.
 *
 *   #include <c_asm.h>
 *
 *   main()
 *       {
 *        long retaddr;
 *
 *        retaddr = asm("mov %ra, %v0");
 *
 *        printf("%x\n", retaddr);
 *       }
 *
 *
 *    **While inline assembly code is usually convenient and efficient
 *	for coding simple sequences of machine instructions and PAL calls,
 *      the DEC C compiler also supports a number of specialized "builtin
 *	functions" that reliably and efficiently implement a collection of
 *	more complex load-locked/store-conditional instruction sequences
 *	that perform atomic updates to memory locations.  See
 *	machine/builtins.h and the Programmers Guide for more information.
 *
 * C++ users:
 *
 * DEC C++ versions prior to V5.3 DO NOT support the intrinsic routines
 * below.  If using a pre-V5.3 versions of DEC C++, this header and these
 * routines SHOULD NOT be used.  The result would be a compilation warning
 * regarding the #pragma intrinsics below.  However, there are no alternate
 * versions of these routines in the standard C library, so there is no
 * suitable workaround for pre-V5.3 DEC C++ users.  Please do not use this
 * header under pre-V5.3 versions of the DEC C++ compiler.
 */

	float  fasm( const char *,... );
	long   asm( const char *,...);
	double dasm( const char *,... );

#pragma intrinsic( fasm )
#pragma intrinsic( asm )
#pragma intrinsic( dasm )

#ifdef __cplusplus
}
#endif
#endif /* __C_ASM_H */

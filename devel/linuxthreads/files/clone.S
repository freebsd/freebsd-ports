	.file	"clone.S"
#include <sys/syscall.h>
#if __FreeBSD__ >= 5
#include <machine/asm.h>
#else		
#include "DEFS.h"
#endif
#include "SYS.h"
#define KERNEL
#define _KERNEL
#include <sys/errno.h>
#undef _KERNEL
#undef KERNEL

#undef DEBUG

/*
 *         8      12            16        20  
 * _clone (__fn,  __childstack, __flags,  __arg);	
 *
 * Here's the idea:
 *   __childstack is the TOS for the new rforked thread
 *   __flags are the rfork flags
 *   __fn is the userland function go be started for the new thread
 *        as in:
 *	
 *       int __fn (void * __arg)	
 *
 */
.stabs "clone.S",100,0,0,Ltext0
	.text
Ltext0:
	.type	CNAME(_clone),@function
	.stabd 68,0,1
ENTRY(_clone)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	PIC_PROLOGUE

	/*
	 * Push thread info onto the new thread's stack
	 */
	movl	12(%ebp), %esi		/* get stack addr */

	subl	$4, %esi
	andl	$-16, %esi		/* Align stack addr */		
	movl	20(%ebp), %eax		/* get __arg */
	movl	%eax, (%esi)

	subl	$4, %esi
	movl	8(%ebp), %eax		/* get __fn */
	movl	%eax, (%esi)

	.stabd 68,0,2
	/*
	 * Prepare and execute rfork
	 */
	pushl	16(%ebp)
	pushl	$0			/* fake return address */

	leal	SYS_rfork, %eax
	KERNCALL
	jb 	2f

	.stabd 68,0,3
	/*
	 * Check to see if we are in the parent or child
	 */
	cmpl	$0, %edx
	jnz	1f
	addl	$8, %esp
	PIC_EPILOGUE
	popl	%esi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 2

	/*
	 * If we are in the child (new thread), then
	 * set-up the call to the internal subroutine.  If it
	 * returns, then call _exit.
	 */
	.stabd 68,0,4
1:
	movl	%esi,%esp
#ifdef DEBUG
	movl	%esp, _stackaddr
	movl	(%esp), %eax
	movl	%eax, _stack
	movl	4(%esp), %eax
	movl	%eax,_stack+4
	movl	8(%esp), %eax
	movl	%eax,_stack+8
#endif
	popl	%eax 
#ifdef DEBUG
	movl	%eax,_fcn
#endif
	movl	$0, %ebp		
	call	*%eax
	addl	$8, %esp

	/*
	 * Exit system call
	 */
	call	PIC_PLT(_exit)

	.stabd 68,0,5
2:	addl	$8, %esp
	PIC_EPILOGUE
	popl	%esi
	movl	%ebp, %esp
	popl	%ebp
	PIC_PROLOGUE
	/* Copy of libc .cerror since libc .cerror must be called from libc */
	pushl	%eax
	/* The caller must execute the PIC prologue before jumping to cerror. */
	call	PIC_PLT(CNAME(__error))
	popl	%ecx
	PIC_EPILOGUE
	movl	%ecx,(%eax)
	movl	$-1,%eax
	movl	$-1,%edx
	ret

.stabs "_clone:f67",36,0,6,CNAME(_clone)
Lfe1:
	.size	 CNAME(_clone),Lfe1-CNAME(_clone)

#ifdef DEBUG
	.data
	.globl	_stack
_stack:	.long	0
	.long	0
	.long	0
	.long	0
	.globl	_stackaddr
_stackaddr:	.long	0
	.globl	_fcn
_fcn:	.long	0
#endif

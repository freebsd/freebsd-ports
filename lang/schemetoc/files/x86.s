/*
 * SCHEME->C
 *
 * x86 assembly code.
 *
 * This code originally came from the Linux port, so someone else gets
 * the credit for writing it.
 *
 */

#ifdef	__i486__
	.align 4
#else
	.align 2
#endif
.globl	sc_geti386regs

sc_geti386regs:
	pushl %ebp
	movl %esp,%ebp
	pushl %ecx
	movl %eax,%ecx
	movl 8(%ebp),%eax
	movl %ecx,(%eax)
	popl %ecx
	movl %ecx,4(%eax)
	movl %edx,8(%eax)
	movl %ebx,12(%eax)
	movl %esi,16(%eax)
	movl %edi,20(%eax)
	movl %ebp,%esp
	popl %ebp
	ret


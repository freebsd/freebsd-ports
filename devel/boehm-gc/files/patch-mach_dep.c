--- mach_dep.c.orig	Tue Dec  2 09:04:34 2003
+++ mach_dep.c	Sun Oct 31 02:13:04 2004
@@ -465,7 +465,7 @@
 /* the stack.	Return sp.						*/
 # ifdef SPARC
     asm("	.seg 	\"text\"");
-#   if defined(SVR4) || defined(NETBSD)
+#   if defined(SVR4) || defined(NETBSD) || defined(FREEBSD)
       asm("	.globl	GC_save_regs_in_stack");
       asm("GC_save_regs_in_stack:");
       asm("	.type GC_save_regs_in_stack,#function");

--- libdv/mmx.h.orig	Thu Apr 26 16:08:25 2001
+++ libdv/mmx.h	Sun Feb 10 11:03:54 2002
@@ -72,6 +72,9 @@
 	__asm__ __volatile__ (
 		/* See if CPUID instruction is supported ... */
 		/* ... Get copies of EFLAGS into eax and ecx */
+                "pushl %%ebx\n\t"
+                "pushl %%ecx\n\t"
+                "pushl %%edx\n\t"
 		"pushf\n\t"
 		"popl %%eax\n\t"
 		"movl %%eax, %%ecx\n\t"
@@ -207,9 +210,11 @@
 		"movl $0, %0\n\n\t"
 
 		"Return:\n\t"
+                "popl %%edx\n\t"
+                "popl %%ecx\n\t"
+                "popl %%ebx\n\t"
 		: "=a" (rval)
 		: /* no input */
-		: "ebx", "ecx", "edx"
 	);
 
 	/* Return */

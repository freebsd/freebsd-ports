
$FreeBSD$

--- pnggccrd.c	2001/11/15 23:03:00	1.1
+++ pnggccrd.c	2001/11/15 23:07:03
@@ -5287,6 +5287,8 @@
         "popfl                \n\t"  // restore modified value to Eflag reg
         "pushfl               \n\t"  // save Eflag to stack
         "popl %%eax           \n\t"  // get Eflag from stack
+        "pushl %%ecx          \n\t"  // save original Eflag to stack
+        "popfl                \n\t"  // restore original Eflag
         "xorl %%ecx, %%eax    \n\t"  // compare new Eflag with original Eflag
         "jz .NOT_SUPPORTED    \n\t"  // if same, CPUID instr. is not supported
 

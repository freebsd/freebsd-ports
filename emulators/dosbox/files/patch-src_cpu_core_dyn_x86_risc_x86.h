--- src/cpu/core_dyn_x86/risc_x86.h.orig	2014-12-31 12:59:53.015190887 +0000
+++ src/cpu/core_dyn_x86/risc_x86.h	2014-12-31 13:00:30.953180886 +0000
@@ -138,7 +138,7 @@
 		"run_return_adress:					\n"
 		"popl %%ebp							\n"
 		:"=a" (retval), "=c" (tempflags)
-		:"r" (tempflags),"r" (code)
+		:"a" (tempflags),"r" (code)
 		:"%edx","%ebx","%edi","%esi","cc","memory"
 	);
 	reg_flags=(reg_flags & ~FMASK_TEST) | (tempflags & FMASK_TEST);

--- src/cpu/core_dyn_x86/risc_x86.h.orig	2022-07-01 13:24:06 UTC
+++ src/cpu/core_dyn_x86/risc_x86.h
@@ -137,7 +137,7 @@ return_address:
 		"run_return_adress:					\n"
 		"popl %%ebp							\n"
 		:"=a" (retval), "=c" (tempflags)
-		:"r" (tempflags),"r" (code)
+		:"a" (tempflags),"r" (code)
 		:"%edx","%ebx","%edi","%esi","cc","memory"
 	);
 	reg_flags=(reg_flags & ~FMASK_TEST) | (tempflags & FMASK_TEST);

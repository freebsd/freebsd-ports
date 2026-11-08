--- src/filter-amd64-mmx.h.orig	2005-03-01 09:07:35 UTC
+++ src/filter-amd64-mmx.h
@@ -59,16 +59,15 @@
 
 		"convmmx"FILTMMX_SKIP_ADD_STR":\n\t"
 
-		"mov (%%rax), %%rbp\n\t"
-		//"sar $15, %%rbp\n\t"
-		"sar $47, %%rbp\n\t"
+		"movl (%%rax), %%ebp\n\t"
+		"sarl $15, %%ebp\n\t"
 		#ifndef FILTMMX_SKIP_ADD
-		"add $32767, %%rbp\n\t"
+		"addl $32767, %%ebp\n\t"
 		#endif
-		"mov %%rbp, (%%rax)\n\t"
+		"movl %%ebp, (%%rax)\n\t"
 
-		"fild (%%rax)\n\t"
-		"fstp (%%rax)\n\t"
+		"fildl (%%rax)\n\t"
+		"fstps (%%rax)\n\t"
 		"add $4, %%rax\n\t"
 		"dec %%rcx\n\t"
 		"jnz convmmx"FILTMMX_SKIP_ADD_STR"\n\t"

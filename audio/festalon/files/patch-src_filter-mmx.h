--- src/filter-mmx.h.orig	2005-03-01 09:20:48 UTC
+++ src/filter-mmx.h
@@ -68,7 +68,7 @@
 		"movl %%ebp, (%%eax)\n\t"
 
 		"fildl (%%eax)\n\t"
-		"fstp (%%eax)\n\t"
+		"fstps (%%eax)\n\t"
 		"addl $4, %%eax\n\t"
 		"decl %%ecx\n\t"
 		"jnz convmmx"FILTMMX_SKIP_ADD_STR"\n\t"

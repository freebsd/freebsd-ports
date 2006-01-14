--- support/stdio.c.orig	Fri Oct 14 07:58:02 2005
+++ support/stdio.c	Mon Nov 14 21:08:53 2005
@@ -197,7 +197,7 @@
 Mono_Posix_Stdlib_clearerr (void* stream)
 {
 	errno = 0;
-	clearerr (stream);
+	clearerr ((FILE *) stream);
 	return errno == 0 ? 0 : -1;
 }
 

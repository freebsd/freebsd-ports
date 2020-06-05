--- input-files.c.orig	2020-06-05 00:33:03 UTC
+++ input-files.c
@@ -48,7 +48,7 @@ FILE * f_subr_open(const char * fname, const char * mo
 #ifdef __MINGW32__
 		return fopen64(fname, mode);
 #else
-#if defined(__LP64__) || defined(_LP64) || defined(MACOS) 
+#if defined(__LP64__) || defined(_LP64) || defined(MACOS) || defined(__FreeBSD__)
 		return fopen(fname, mode);
 #else
 		return fopen64(fname, mode);

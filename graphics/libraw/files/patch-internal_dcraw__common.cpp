Use strnlen(3) and strcasestr(3) from FreeBSD's libc instead of the bundled
versions. Patch has been applied upstream in master branch:
https://github.com/LibRaw/LibRaw/commit/b1a2984

--- internal/dcraw_common.cpp.orig	2017-09-22 06:35:16 UTC
+++ internal/dcraw_common.cpp
@@ -51,6 +51,8 @@ int CLASS fcol (int row, int col)
   if (filters == 9) return xtrans[(row+6) % 6][(col+6) % 6];
   return FC(row,col);
 }
+
+#if !defined(__FreeBSD__)
 static size_t local_strnlen(const char *s, size_t n)
 {
   const char *p = (const char *)memchr(s, 0, n);
@@ -58,6 +60,7 @@ static size_t local_strnlen(const char *
 }
 /* add OS X version check here ?? */
 #define strnlen(a,b) local_strnlen(a,b)
+#endif
 
 #ifdef LIBRAW_LIBRARY_BUILD
 static int stread(char *buf, size_t len, LibRaw_abstract_datastream *fp)
@@ -69,7 +72,7 @@ static int stread(char *buf, size_t len,
 #define stmread(buf,maxlen,fp) stread(buf,MIN(maxlen,sizeof(buf)),fp)
 #endif
 
-#ifndef __GLIBC__
+#if !defined(__GLIBC__) && !defined(__FreeBSD__)
 char *my_memmem (char *haystack, size_t haystacklen,
 	      char *needle, size_t needlelen)
 {

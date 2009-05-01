--- src/plld.c.orig	2009-04-30 17:13:29.527991549 -0400
+++ src/plld.c	2009-04-30 19:37:05.199263456 -0400
@@ -114,6 +114,9 @@
 #include <errno.h>
 #include <string.h>
 #include <signal.h>
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#endif
 
 #ifndef TRUE
 #define TRUE 1
@@ -143,8 +146,9 @@
 #define oserror xoserror
 #undef strdup
 #define strdup plld_strdup
-#undef strndup
+#ifndef strndup
 #define strndup plld_strndup
+#endif
 #ifdef HAVE_DMALLOC_H
 #undef xmalloc
 #undef xrealloc

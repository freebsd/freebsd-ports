--- src/swipl-ld.c.orig	2011-08-19 18:31:28.000000000 +0400
+++ src/swipl-ld.c	2011-10-08 21:00:16.000000000 +0400
@@ -110,6 +110,9 @@
 #include <errno.h>
 #include <string.h>
 #include <signal.h>
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#endif
 
 #ifndef TRUE
 #define TRUE 1
@@ -139,8 +142,9 @@
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

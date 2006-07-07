--- regex.c.orig	Wed Apr 19 12:58:00 1995
+++ regex.c	Thu Jul  6 22:30:45 2006
@@ -114,7 +114,7 @@
  * Date :	 July 27, 1990
  */
 
-#ifndef NeXT
+#if !defined(NeXT) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 #include <string.h>
@@ -123,7 +123,7 @@
 #include <assert.h>
 
 #ifdef sparc
-#include <alloca.h>
+/* #include <alloca.h> */
 #else
 #pragma alloca
 #endif

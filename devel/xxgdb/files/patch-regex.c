--- regex.c.orig	1995-04-19 16:58:00 UTC
+++ regex.c
@@ -114,7 +114,7 @@ what you give them.   Help stamp out sof
  * Date :	 July 27, 1990
  */
 
-#ifndef NeXT
+#if !defined(NeXT) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 #include <malloc.h>
 #endif
 #include <string.h>
@@ -123,7 +123,7 @@ what you give them.   Help stamp out sof
 #include <assert.h>
 
 #ifdef sparc
-#include <alloca.h>
+/* #include <alloca.h> */
 #else
 #pragma alloca
 #endif

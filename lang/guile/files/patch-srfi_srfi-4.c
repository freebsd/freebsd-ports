--- srfi/srfi-4.c.orig	Sat Nov 20 17:30:56 2004
+++ srfi/srfi-4.c	Sat Nov 20 17:31:55 2004
@@ -50,6 +50,10 @@
 #include <string.h>
 #include <stdio.h>
 
+#ifndef SIZE_MAX
+#define SIZE_MAX ((size_t) (-1))
+#endif
+
 /* For brevity and maintainability, we define our own types for the
    various integer and floating point types.  */
 typedef unsigned char int_u8;

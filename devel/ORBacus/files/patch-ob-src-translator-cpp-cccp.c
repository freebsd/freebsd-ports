--- ob/src/translator/cpp/cccp.c.orig	Tue Oct 28 06:48:49 2003
+++ ob/src/translator/cpp/cccp.c	Tue Oct 28 06:54:31 2003
@@ -174,6 +174,7 @@
 # endif
 #endif
 
+#define HAVE_VPRINTF
 #if defined (__STDC__) && defined (HAVE_VPRINTF)
 # include <stdarg.h>
 # define VA_START(va_list, var) va_start (va_list, var)

--- ./libtest/lite.h.orig	2013-07-17 14:36:43.000000000 -0400
+++ ./libtest/lite.h	2013-07-17 14:37:02.000000000 -0400
@@ -53,6 +53,8 @@
 
 #if defined(WIN32)
 # include <malloc.h>
+#elif defined(__FreeBSD__)
+# include <stdlib.h>
 #else
 # include <alloca.h>
 #endif

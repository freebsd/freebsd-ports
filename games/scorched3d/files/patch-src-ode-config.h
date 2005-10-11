--- ./src/ode/config.h.orig	Sat Aug  6 13:57:39 2005
+++ ./src/ode/config.h	Tue Aug  9 23:21:22 2005
@@ -36,7 +36,7 @@
 #if defined(__DARWIN__)
 #include <sys/malloc.h>
 #else
-#include <malloc.h>            // for alloca under windows
+#include <stdlib.h>            // for alloca under windows
 #endif
 
 #include <string.h>

--- ./src/ode/config.h.orig	Tue Nov  2 10:20:35 2004
+++ ./src/ode/config.h	Tue Jan 25 19:34:28 2005
@@ -36,7 +36,7 @@
 #if defined(__DARWIN__)
 #include <sys/malloc.h>
 #else
-#include <malloc.h>            // for alloca under windows
+#include <stdlib.h>            // for alloca under windows
 #endif
 
 #include <string.h>

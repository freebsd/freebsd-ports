--- ./src/ode/config.h.orig	Mon May 24 21:02:31 2004
+++ ./src/ode/config.h	Sun May 30 14:38:24 2004
@@ -36,7 +36,7 @@
 #if defined(__DARWIN__)
 #include <sys/malloc.h>
 #else
-#include <malloc.h>            // for alloca under windows
+#include <stdlib.h>            // for alloca under windows
 #endif
 
 #include <string.h>

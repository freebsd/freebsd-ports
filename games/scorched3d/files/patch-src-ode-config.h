--- ./src/ode/config.h.orig	Fri Jan 23 17:59:18 2004
+++ ./src/ode/config.h	Fri Jan 23 18:03:31 2004
@@ -35,7 +35,7 @@
 #if defined(__DARWIN__)
 #include <sys/malloc.h>
 #else
-#include <malloc.h>            // for alloca under windows
+#include <stdlib.h>            // for alloca under windows
 #endif
 
 #include <string.h>

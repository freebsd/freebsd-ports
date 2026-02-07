--- ./contrib/bobtoolz/misc.cpp.orig	Thu Mar 16 16:09:46 2006
+++ ./contrib/bobtoolz/misc.cpp	Thu Mar 16 16:37:50 2006
@@ -33,7 +33,7 @@
 
 #include "funchandlers.h"
 
-#ifdef __linux__
+#if defined (__linux__) || defined(__FreeBSD__)
 #include <sys/types.h>
 #include <unistd.h>
 #endif

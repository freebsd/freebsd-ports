--- rts/lib/gml/speedy-tls.cpp.orig	2010-09-06 16:16:18.000000000 +0400
+++ rts/lib/gml/speedy-tls.cpp	2010-09-15 23:37:21.000000000 +0400
@@ -3,7 +3,7 @@
 //Contains macros that can be used to very quickly (one instruction) access thread-local memory.
 
 #ifdef USE_GML
-#ifndef _WIN32
+#if defined(__linux__) || defined(__APPLE__)
 
 #include "speedy-tls.h"
 #include <stdlib.h>

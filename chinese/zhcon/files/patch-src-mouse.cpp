--- src/mouse.cpp.orig	Sat Aug 16 16:36:28 2003
+++ src/mouse.cpp	Sat Aug 16 16:36:39 2003
@@ -18,6 +18,7 @@
 
 #include "debug.h"
 #include "mouse.h"
+#include <cassert>
 #include <sys/signal.h>
 
 #if defined(__FreeBSD__)

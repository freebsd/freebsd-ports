--- src/freeocl.h.orig	2013-11-15 21:18:17.000000000 +0100
+++ src/freeocl.h	2013-11-15 21:24:32.000000000 +0100
@@ -26,6 +26,7 @@
 #include "dispatch.h"
 #include <iostream>
 #include <deque>
+#include <sys/types.h>
 
 #ifdef DEBUG_UTILS
 #define MSG(X)	std::cout << #X << std::endl

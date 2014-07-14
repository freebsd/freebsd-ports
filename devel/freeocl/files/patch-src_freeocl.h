--- src/freeocl.h.orig	2012-09-02 19:00:41.000000000 +0200
+++ src/freeocl.h	2014-07-04 08:42:48.000000000 +0200
@@ -26,6 +26,8 @@
 #include "dispatch.h"
 #include <iostream>
 #include <deque>
+#include <sys/types.h>
+#include <xmmintrin.h>
 
 #ifdef DEBUG_UTILS
 #define MSG(X)	std::cout << #X << std::endl

--- include/mitsuba/render/gkdtree.h.orig	2015-07-15 10:37:38 UTC
+++ include/mitsuba/render/gkdtree.h
@@ -26,7 +26,7 @@
 #include <stack>
 
 #if defined(__LINUX__)
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 /// Activate lots of extra checks
@@ -1256,7 +1256,7 @@ protected:
 		KDLog(m_logLevel, "   Final cost                  : %.2f", heuristicCost);
 		KDLog(m_logLevel, "");
 
-		#if defined(__LINUX__)
+		#if defined(__LINUX__) && !defined(__FreeBSD__)
 			/* Forcefully release Heap memory back to the OS */
 			malloc_trim(0);
 		#endif

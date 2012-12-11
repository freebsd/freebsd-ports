--- cvstree/CvsLog.h.orig	2002-06-16 02:49:37.000000000 +0900
+++ cvstree/CvsLog.h	2012-11-06 16:19:38.000000000 +0900
@@ -26,8 +26,9 @@
 #endif /* WIN32 */
 
 #include <vector>
-#include <time.h>
-#include <stdio.h>
+#include <ctime>
+#include <cstdio>
+#include <cstring>
 
 #if defined(_MSC_VER) && _MSC_VER < 0x514 // VC7
 #	include <iostream.h>

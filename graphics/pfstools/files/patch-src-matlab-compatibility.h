--- src/matlab/compatibility.h.orig	2007-03-01 14:10:57.000000000 +0000
+++ src/matlab/compatibility.h	2014-02-20 19:04:01.566588122 +0000
@@ -59,6 +59,6 @@
 
 #endif
 
-#define DEBUG_STR if(1); else cerr
+#define DEBUG_STR if(1); else std::cerr
 
 #endif

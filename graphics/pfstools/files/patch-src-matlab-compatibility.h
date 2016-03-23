--- src/matlab/compatibility.h.orig	2007-03-01 14:10:57 UTC
+++ src/matlab/compatibility.h
@@ -59,6 +59,6 @@
 
 #endif
 
-#define DEBUG_STR if(1); else cerr
+#define DEBUG_STR if(1); else std::cerr
 
 #endif

--- src/include/main.h.orig	2016-12-07 04:15:22 UTC
+++ src/include/main.h
@@ -22,6 +22,8 @@
 #define MAIN_H_
 
 #include <config.h>
+// FreeBSD needs this 
+#include <time.h>
 
 #include <string>
 

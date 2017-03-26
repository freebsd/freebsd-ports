--- src/include/main.h.orig	2017-01-29 13:26:25 UTC
+++ src/include/main.h
@@ -22,6 +22,8 @@
 #define MAIN_H_
 
 #include <config.h>
+// FreeBSD needs this 
+#include <time.h>
 
 #include <string>
 

--- vv/vv.cxx.orig	2020-09-19 05:31:12 UTC
+++ vv/vv.cxx
@@ -53,7 +53,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <errno.h>
-#pragma comment(lib, "ws2_32.lib")
+//#pragma comment(lib, "ws2_32.lib")
 
 typedef enum {O_BASE,O_OVERLAY,O_FUSION,O_VF,O_CONTOUR,O_LANDMARKS} OpenModeType;
 typedef enum {P_NORMAL,P_SEQUENCE,P_WINDOW,P_LEVEL} ParseModeType;

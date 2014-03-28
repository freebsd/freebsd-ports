--- 3rdparty/iaxclient/lib/iaxclient.h.orig	2014-03-17 07:06:55.000000000 +0100
+++ 3rdparty/iaxclient/lib/iaxclient.h	2014-03-17 07:09:42.000000000 +0100
@@ -45,6 +45,8 @@
 #include <sys/socket.h>
 #endif
 
+#include <sys/time.h>
+
 #ifdef BUILDING_DLL
 # if defined(WIN32) ||  defined(_WIN32_WCE)
 #  ifdef _MSC_VER

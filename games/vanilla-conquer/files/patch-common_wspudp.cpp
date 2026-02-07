--- common/wspudp.cpp.orig	2022-08-04 11:21:27 UTC
+++ common/wspudp.cpp
@@ -54,6 +54,7 @@ extern WWKeyboardClass* Keyboard;
 #include <assert.h>
 
 #ifndef _WIN32
+#include <netinet/in.h>
 #include <ifaddrs.h>
 #endif
 

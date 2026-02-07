--- c++/jackbridge/JackBridgeDefines.hpp.orig	2017-07-07 18:23:41 UTC
+++ c++/jackbridge/JackBridgeDefines.hpp
@@ -28,6 +28,8 @@
 # define JACKBRIDGE_OS_HAIKU
 #elif defined(__linux__) || defined(__linux)
 # define JACKBRIDGE_OS_LINUX
+#elif defined(__FreeBSD__)
+# define JACKBRIDGE_OS_FREEBSD
 #else
 # warning Unsupported platform!
 #endif

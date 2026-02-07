--- src/cpp/jssc_SerialNativeInterface.h.orig	2016-10-24 19:47:55 UTC
+++ src/cpp/jssc_SerialNativeInterface.h
@@ -43,6 +43,8 @@ extern "C" {
 #define jssc_SerialNativeInterface_OS_SOLARIS 2L
 #undef jssc_SerialNativeInterface_OS_MAC_OS_X
 #define jssc_SerialNativeInterface_OS_MAC_OS_X 3L
+#undef jssc_SerialNativeInterface_OS_FREEBSD
+#define jssc_SerialNativeInterface_OS_FREEBSD 4L
 #undef jssc_SerialNativeInterface_ERR_PORT_BUSY
 #define jssc_SerialNativeInterface_ERR_PORT_BUSY -1LL
 #undef jssc_SerialNativeInterface_ERR_PORT_NOT_FOUND

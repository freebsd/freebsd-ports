--- src/rtapi/rtapi_parport.h.orig	2016-06-25 02:19:12 UTC
+++ src/rtapi/rtapi_parport.h
@@ -16,6 +16,8 @@
 #ifndef RTAPI_PARPORT_H
 #define RTAPI_PARPORT_H
 
+#ifdef __linux__
+
 #include <rtapi.h>
 #include <rtapi_io.h>
 #include <linux/parport.h>
@@ -239,3 +241,4 @@ void rtapi_parport_release(rtapi_parport
 RTAPI_END_DECLS
 
 #endif
+#endif /* __linux__ */

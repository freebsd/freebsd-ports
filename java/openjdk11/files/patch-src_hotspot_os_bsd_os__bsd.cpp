--- src/hotspot/os/bsd/os_bsd.cpp
+++ src/hotspot/os/bsd/os_bsd.cpp
@@ -377,8 +377,10 @@ void os::init_system_properties_values() {
 #ifndef DEFAULT_LIBPATH
 #ifdef __APPLE__
   #define DEFAULT_LIBPATH "/lib:/usr/lib"
+#elif defined(__NetBSD__)
+  #define DEFAULT_LIBPATH "/usr/lib:/usr/pkg/lib"
 #else
-  #define DEFAULT_LIBPATH "/usr/lib:" PACKAGE_PATH "/lib"
+  #define DEFAULT_LIBPATH "/usr/lib:%%LOCALBASE%%/lib"
 #endif
 #endif
 

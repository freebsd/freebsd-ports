--- src/hotspot/os/bsd/os_bsd.cpp.orig	2019-03-28 21:47:08.000000000 -0700
+++ src/hotspot/os/bsd/os_bsd.cpp	2019-03-28 23:08:55.590922000 -0700
@@ -361,7 +361,7 @@
     #elif defined(__NetBSD__)
       #define DEFAULT_LIBPATH "/usr/lib:/usr/pkg/lib"
     #else
-      #define DEFAULT_LIBPATH "/usr/lib:/usr/local/lib"
+      #define DEFAULT_LIBPATH "/usr/lib:%%LOCALBASE%%/lib"
     #endif
   #else
     #define DEFAULT_LIBPATH OVERRIDE_LIBPATH

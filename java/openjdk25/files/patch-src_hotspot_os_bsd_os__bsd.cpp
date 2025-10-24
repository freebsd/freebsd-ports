--- src/hotspot/os/bsd/os_bsd.cpp.orig	2021-09-29 21:25:10 UTC
+++ src/hotspot/os/bsd/os_bsd.cpp
@@ -361,7 +361,7 @@
     #elif defined(__NetBSD__)
       #define DEFAULT_LIBPATH "/usr/lib:/usr/pkg/lib"
     #else
-      #define DEFAULT_LIBPATH "/usr/lib:/usr/local/lib"
+      #define DEFAULT_LIBPATH "/usr/lib:%%LOCALBASE%%/lib"
     #endif
   #else
     #define DEFAULT_LIBPATH OVERRIDE_LIBPATH

--- src/hotspot/os/bsd/os_bsd.cpp.orig	2019-03-27 13:28:54.000000000 -0700
+++ src/hotspot/os/bsd/os_bsd.cpp	2019-03-28 16:46:31.000797000 -0700
@@ -380,7 +380,7 @@
 #elif defined(__NetBSD__)
   #define DEFAULT_LIBPATH "/usr/lib:/usr/pkg/lib"
 #else
-  #define DEFAULT_LIBPATH "/usr/lib:/usr/local/lib"
+  #define DEFAULT_LIBPATH "/usr/lib:%%LOCALBASE%%/lib"
 #endif
 #endif
 

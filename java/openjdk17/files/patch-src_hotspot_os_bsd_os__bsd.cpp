--- src/hotspot/os/bsd/os_bsd.cpp.orig	2021-09-29 21:25:10 UTC
+++ src/hotspot/os/bsd/os_bsd.cpp
@@ -58,6 +58,7 @@
 #include "runtime/thread.inline.hpp"
 #include "runtime/threadCritical.hpp"
 #include "runtime/timer.hpp"
+#include "runtime/vm_version.hpp"
 #include "services/attachListener.hpp"
 #include "services/memTracker.hpp"
 #include "services/runtimeService.hpp"
@@ -361,7 +361,7 @@
     #elif defined(__NetBSD__)
       #define DEFAULT_LIBPATH "/usr/lib:/usr/pkg/lib"
     #else
-      #define DEFAULT_LIBPATH "/usr/lib:/usr/local/lib"
+      #define DEFAULT_LIBPATH "/usr/lib:%%LOCALBASE%%/lib"
     #endif
   #else
     #define DEFAULT_LIBPATH OVERRIDE_LIBPATH

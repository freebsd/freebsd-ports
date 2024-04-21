--- lib/third_party/jthread/includes/jthread.hpp.orig	2024-03-23 09:15:12 UTC
+++ lib/third_party/jthread/includes/jthread.hpp
@@ -1,6 +1,11 @@
 #pragma once
 
-#if __cpp_lib_jthread >= 201911L
+#include <osreldate.h>
+
+#if __cpp_lib_jthread >= 201911L \
+    || (__FreeBSD_version >= 1500000 && __FreeBSD_version >= 1500018) \
+    || (__FreeBSD_version >= 1400000 && __FreeBSD_version >= 1400511) \
+    || (__FreeBSD_version >= 1300000 && __FreeBSD_version >= 1303503)
     #include <thread>
 #else
     #include "../jthread/source/jthread.hpp"

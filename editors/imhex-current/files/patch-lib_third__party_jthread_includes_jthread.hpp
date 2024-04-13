--- lib/third_party/jthread/includes/jthread.hpp.orig	2024-04-13 11:34:49 UTC
+++ lib/third_party/jthread/includes/jthread.hpp
@@ -1,6 +1,8 @@
 #pragma once
 
-#if __cpp_lib_jthread >= 201911L
+#include <osreldate.h>
+
+#if __cpp_lib_jthread >= 201911L || __FreeBSD_version >= 1500018
     #include <thread>
 #else
     #include "../jthread/source/jthread.hpp"

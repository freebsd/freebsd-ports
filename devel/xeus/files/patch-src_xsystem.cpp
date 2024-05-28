--- src/xsystem.cpp.orig	2024-05-28 08:04:00 UTC
+++ src/xsystem.cpp
@@ -23,6 +23,8 @@
 #  include <mach-o/dyld.h>
 #endif
 
+#include <sys/sysctl.h>
+
 #include "xeus/xsystem.hpp"
 #include "xeus/xhash.hpp"
 

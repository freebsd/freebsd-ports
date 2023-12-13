--- libcc1/libcc1plugin.cc.orig	2023-07-27 08:13:07 UTC
+++ libcc1/libcc1plugin.cc
@@ -32,6 +32,7 @@
 #undef PACKAGE_VERSION
 
 #define INCLUDE_MEMORY
+#define INCLUDE_VECTOR
 #include "gcc-plugin.h"
 #include "system.h"
 #include "coretypes.h"
@@ -68,8 +69,6 @@
 #include "rpc.hh"
 #include "gcc-c-interface.h"
 #include "context.hh"
-
-#include <vector>
 
 using namespace cc1_plugin;
 

--- libcc1/libcp1plugin.cc.orig	2023-07-27 08:13:07 UTC
+++ libcc1/libcp1plugin.cc
@@ -33,6 +33,7 @@
 #undef PACKAGE_VERSION
 
 #define INCLUDE_MEMORY
+#define INCLUDE_VECTOR
 #include "gcc-plugin.h"
 #include "system.h"
 #include "coretypes.h"
@@ -70,8 +71,6 @@
 #include "marshall-cp.hh"
 #include "rpc.hh"
 #include "context.hh"
-
-#include <vector>
 
 using namespace cc1_plugin;
 

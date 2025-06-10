--- src/storage/buffer_manager/vm_region.cpp.orig	2025-02-24 14:26:02 UTC
+++ src/storage/buffer_manager/vm_region.cpp
@@ -14,6 +14,10 @@
 
 #include "common/exception/buffer_manager.h"
 
+#ifndef MAP_NORESERVE
+#define MAP_NORESERVE 0
+#endif
+
 using namespace kuzu::common;
 
 namespace kuzu {

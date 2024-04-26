- workaround for https://github.com/secure-software-engineering/phasar/issues/718

--- lib/Pointer/PointsToInfo.cpp.orig	2024-04-26 06:58:43 UTC
+++ lib/Pointer/PointsToInfo.cpp
@@ -19,6 +19,7 @@
 
 #include <array>
 #include <utility>
+#include <vector>
 
 namespace llvm {
 class Value;

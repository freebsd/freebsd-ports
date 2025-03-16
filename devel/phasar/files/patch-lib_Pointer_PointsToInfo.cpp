- workaround for https://github.com/secure-software-engineering/phasar/issues/718

--- lib/Pointer/PointsToInfo.cpp.orig	2025-03-14 12:56:24 UTC
+++ lib/Pointer/PointsToInfo.cpp
@@ -20,6 +20,7 @@
 #include <array>
 #include <tuple>
 #include <utility>
+#include <vector>
 
 namespace llvm {
 class Value;

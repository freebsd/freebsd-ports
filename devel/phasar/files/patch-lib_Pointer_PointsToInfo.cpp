- workaround for https://github.com/secure-software-engineering/phasar/issues/718

--- lib/Pointer/PointsToInfo.cpp.orig	2026-10-24 10:43:11 UTC
+++ lib/Pointer/PointsToInfo.cpp
@@ -21,6 +21,7 @@
 #include <array>
 #include <tuple>
 #include <utility>
+#include <vector>
 
 namespace llvm {
 class Value;

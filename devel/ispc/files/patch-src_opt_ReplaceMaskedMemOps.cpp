--- src/opt/ReplaceMaskedMemOps.cpp.orig	2024-06-01 22:09:03 UTC
+++ src/opt/ReplaceMaskedMemOps.cpp
@@ -9,6 +9,7 @@
 #include <llvm/IR/IRBuilder.h>
 #include <llvm/Transforms/Utils/Local.h>
 
+#include <unordered_map>
 #include <numeric>
 
 namespace ispc {

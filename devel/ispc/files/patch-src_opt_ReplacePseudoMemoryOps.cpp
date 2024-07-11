--- src/opt/ReplacePseudoMemoryOps.cpp.orig	2024-06-01 21:18:54 UTC
+++ src/opt/ReplacePseudoMemoryOps.cpp
@@ -7,6 +7,8 @@
 #include "ReplacePseudoMemoryOps.h"
 #include "builtins-decl.h"
 
+#include <unordered_map>
+
 namespace ispc {
 
 using namespace builtin;

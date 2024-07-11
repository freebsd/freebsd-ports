--- src/opt/ImproveMemoryOps.cpp.orig	2024-06-01 21:03:34 UTC
+++ src/opt/ImproveMemoryOps.cpp
@@ -7,6 +7,8 @@
 #include "ImproveMemoryOps.h"
 #include "builtins-decl.h"
 
+#include <unordered_map>
+
 namespace ispc {
 
 using namespace builtin;

--- core/vm.cpp.orig	2025-05-07 12:28:56 UTC
+++ core/vm.cpp
@@ -1726,6 +1726,10 @@ class Interpreter {
                 abort();
             }
 
+            case json::value_t::binary: {
+                abort();
+            }
+
             default: {
                 // Newer nlohmann json.hpp (from v3.8.0 https://github.com/nlohmann/json/pull/1662)
                 // add a `value_t::binary` type, used when dealing with some JSON-adjacent binary

--- zeno/src/nodes/neo/PrimUnmerge.cpp.orig	2024-09-30 13:46:54 UTC
+++ zeno/src/nodes/neo/PrimUnmerge.cpp
@@ -224,7 +224,8 @@
             }
             mapping[attr[i]].push_back(i);
         }
-        for (auto &[key, val]: mapping) {
+        for (auto &kv: mapping) {
+            auto &val = kv.second; // clang: structured binding can not be captured with OpenMP
             auto new_prim = std::dynamic_pointer_cast<PrimitiveObject>(prim->clone());
             new_prim->tris.resize(val.size());
             for (auto i = 0; i < val.size(); i++) {
@@ -248,7 +249,8 @@
             }
             mapping[attr[i]].push_back(i);
         }
-        for (auto &[key, val]: mapping) {
+        for (auto &kv: mapping) {
+            auto &val = kv.second; // clang: structured binding can not be captured with OpenMP
             auto new_prim = std::dynamic_pointer_cast<PrimitiveObject>(prim->clone());
             new_prim->polys.resize(val.size());
             for (auto i = 0; i < val.size(); i++) {

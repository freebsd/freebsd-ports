--- src/Layers/xrRender/r__dsgraph_render.cpp.orig	2026-09-30 22:31:46 UTC
+++ src/Layers/xrRender/r__dsgraph_render.cpp
@@ -33,7 +33,7 @@ bool cmp_pass(const T& left, const T& right)
 {
     if (left->first->equal(*right->first))
         return false;
-    return left->second.ssa >= right->second.ssa;
+    return left->second.ssa > right->second.ssa;
 }
 
 void R_dsgraph_structure::render_graph(u32 _priority)

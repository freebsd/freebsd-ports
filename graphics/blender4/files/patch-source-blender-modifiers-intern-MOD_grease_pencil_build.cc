--- source/blender/modifiers/intern/MOD_grease_pencil_build.cc.orig	2025-07-10 09:43:43 UTC
+++ source/blender/modifiers/intern/MOD_grease_pencil_build.cc
@@ -468,7 +468,8 @@ static bke::CurvesGeometry reorder_strokes(const bke::
   }
 
   parallel_sort(
-      distances.begin(), distances.end(), [](Pair &a, Pair &b) { return a.value < b.value; });
+      distances.begin(), distances.end(),
+      [](const Pair &a, const Pair &b) { return a.value < b.value; });
 
   Array<int> new_order(curves.curves_num());
   for (const int i : curves.curves_range()) {

--- src/bitmap.ml.orig	2011-06-22 18:04:32 UTC
+++ src/bitmap.ml
@@ -186,7 +186,7 @@ module Make(B:Bitdepth) = struct
 
   let swap_out_eldest words =
     let sorted =
-      Sort.list (fun b1 b2 -> b1.last_used < b2.last_used) !swappable_blocks in
+      List.sort (fun b1 b2 -> compare b1.last_used b2.last_used) !swappable_blocks in
     let rec swapper sorted i =
      match sorted with
       | [] -> ()

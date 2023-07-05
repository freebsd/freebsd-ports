--- src/unix/lwt_bytes.ml.orig	2016-04-25 14:32:43 UTC
+++ src/unix/lwt_bytes.ml
@@ -219,7 +219,8 @@ let map_file ~fd ?pos ~shared ?(size=(-1)) () =
    +-----------------------------------------------------------------+ *)
 
 let map_file ~fd ?pos ~shared ?(size=(-1)) () =
-  Array1.map_file fd ?pos char c_layout shared size
+  Unix.map_file fd ?pos char c_layout shared [|size|]
+  |> Bigarray.array1_of_genarray
 
 external mapped : t -> bool = "lwt_unix_mapped" "noalloc"
 

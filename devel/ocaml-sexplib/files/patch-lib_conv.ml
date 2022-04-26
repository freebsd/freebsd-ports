--- lib/conv.ml.orig	2015-08-18 11:17:27 UTC
+++ lib/conv.ml
@@ -92,9 +92,9 @@ let sexp_of_float_vec vec =
 
 let sexp_of_bigstring (bstr : bigstring) =
   let n = Array1.dim bstr in
-  let str = String.create n in
-  for i = 0 to n - 1 do str.[i] <- bstr.{i} done;
-  Atom str
+  let str = Bytes.create n in
+  for i = 0 to n - 1 do Bytes.set str i bstr.{i} done;
+  Atom (Bytes.unsafe_to_string str)
 
 let sexp_of_float32_vec (vec : float32_vec) = sexp_of_float_vec vec
 let sexp_of_float64_vec (vec : float64_vec) = sexp_of_float_vec vec
@@ -183,7 +183,7 @@ module Exn_converter = struct
 
   (* [Obj.extension_id] works on both the exception itself, and the extension slot of the
      exception. *)
-  let rec clean_up_handler (slot : Obj.t) =
+  let rec clean_up_handler (slot : extension_constructor) =
     let id = Obj.extension_id slot in
     let old_exn_id_map = !exn_id_map in
     let new_exn_id_map = Exn_ids.remove id old_exn_id_map in
@@ -194,7 +194,7 @@ module Exn_converter = struct
       exn_id_map := new_exn_id_map
 
   let add_auto ?(finalise = true) exn sexp_of_exn =
-    let id = Obj.extension_id exn in
+    let id = Obj.extension_id (Obj.extension_constructor exn) in
     let rec loop () =
       let old_exn_id_map = !exn_id_map in
       let new_exn_id_map = Exn_ids.add id sexp_of_exn old_exn_id_map in
@@ -203,13 +203,18 @@ module Exn_converter = struct
         loop ()
       else begin
         exn_id_map := new_exn_id_map;
-        if finalise then Gc.finalise clean_up_handler (Obj.extension_slot exn)
+        if finalise then
+          try
+            Gc.finalise clean_up_handler (Obj.extension_constructor exn)
+          with Invalid_argument _ ->
+            (* Pre-allocated extension constructors cannot be finalised *)
+            ()
       end
     in
     loop ()
 
   let find_auto exn =
-    let id = Obj.extension_id exn in
+    let id = Obj.extension_id (Obj.extension_constructor exn) in
     match Exn_ids.find id !exn_id_map with
     | exception Not_found -> None
     | sexp_of_exn -> Some (sexp_of_exn exn)

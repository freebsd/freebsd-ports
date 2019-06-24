From cba80ebe02962504fbe404b1baf484a5000f44b4
From: Jeremie Dimino <jdimino@janestreet.com>
Date: Tue, 12 Jul 2016 17:08:10 +0100
Subject: [PATCH] 114.01+04

--- lib/conv.ml.orig	2016-03-09 15:44:55 UTC
+++ lib/conv.ml
@@ -185,7 +185,7 @@ module Exn_converter = struct
 
   (* [Obj.extension_id] works on both the exception itself, and the extension slot of the
      exception. *)
-  let rec clean_up_handler (slot : Obj.t) =
+  let rec clean_up_handler (slot : extension_constructor) =
     let id = Obj.extension_id slot in
     let old_exn_id_map = !exn_id_map in
     let new_exn_id_map = Exn_ids.remove id old_exn_id_map in
@@ -196,7 +196,7 @@ module Exn_converter = struct
       exn_id_map := new_exn_id_map
 
   let add_auto ?(finalise = true) exn sexp_of_exn =
-    let id = Obj.extension_id exn in
+    let id = Obj.extension_id (Obj.extension_constructor exn) in
     let rec loop () =
       let old_exn_id_map = !exn_id_map in
       let new_exn_id_map = Exn_ids.add id sexp_of_exn old_exn_id_map in
@@ -205,13 +205,18 @@ module Exn_converter = struct
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

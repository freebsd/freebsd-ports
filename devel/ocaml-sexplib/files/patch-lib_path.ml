--- lib/path.ml.orig	2015-08-18 11:17:27 UTC
+++ lib/path.ml
@@ -74,10 +74,10 @@ and subst_path sexp = function
 
 let implode lst =
   let len = List.length lst in
-  let str = String.create len in
+  let str = Bytes.create len in
   let rec loop ix = function
-    | h :: t -> str.[ix] <- h; loop (ix + 1) t
-    | [] -> str in
+    | h :: t -> Bytes.set str ix h; loop (ix + 1) t
+    | [] -> Bytes.unsafe_to_string str in
   loop 0 lst
 
 let fail_parse msg = failwith ("Path.parse: " ^ msg)

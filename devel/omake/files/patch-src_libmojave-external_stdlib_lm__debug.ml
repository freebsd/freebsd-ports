$NetBSD: patch-aq,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/stdlib/lm_debug.ml.orig	2006-08-03 22:51:52.000000000 +0000
+++ src/libmojave-external/stdlib/lm_debug.ml
@@ -173,11 +173,10 @@ let create_debug
  *)
 let load_debug name =
    let rec search = function
-      { info_name = name'; info_flag = flag } :: t ->
-         if name' = name then
-            flag
-         else
-            search t
+      info :: _ when info.info_name = name ->
+         info.info_flag
+    | _ :: t ->
+         search t
     | [] ->
          raise (Failure (sprintf "Lm_debug.load_debug: variable '%s' has not been created" name))
    in
@@ -189,11 +188,10 @@ let load_debug name =
 let set_debug name flag =
    let rec search = function
       h :: t ->
-         let { info_name = name'; info_flag = flag' } = h in
-            if name' = name then
-               flag' := flag
-            else
-               search t
+         if h.info_name = name then
+            h.info_flag := flag
+         else
+            search t
     | [] ->
 (*
          (* Try a C function *)
@@ -227,9 +225,8 @@ let get_debug name =
    let rec search = function
       h :: t ->
          if h.info_name = name then
-            let { info_info = description; info_flag = flag } = h in
             let description =
-               match description with
+               match h.info_info with
                   Some desc ->
                      desc
                 | None ->
@@ -237,7 +234,7 @@ let get_debug name =
             in
                { debug_name = name;
                  debug_description = description;
-                 debug_value = !flag
+                 debug_value = !(h.info_flag)
                }
          else
             search t

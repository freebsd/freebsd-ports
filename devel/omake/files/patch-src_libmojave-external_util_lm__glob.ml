$NetBSD: patch-av,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/util/lm_glob.ml.orig	2007-09-04 16:12:33.000000000 +0000
+++ src/libmojave-external/util/lm_glob.ml
@@ -157,11 +157,8 @@ let home_dir =
 let getusers () =
    let users = Lm_unix_util.getpwents () in
       List.map (fun entry ->
-            let { Unix.pw_name = name;
-                  Unix.pw_dir  = dir
-                } = entry
-            in
-               tilde_insert dir name;
+            let name = entry.Unix.pw_name in
+               tilde_insert entry.Unix.pw_dir name;
                name) users
 
 (************************************************************************

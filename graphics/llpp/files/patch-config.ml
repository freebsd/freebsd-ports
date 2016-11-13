--- config.ml.orig	2015-10-13 20:12:27 UTC
+++ config.ml
@@ -1420,17 +1420,7 @@ let do_load f contents =
 ;;
 
 let defconfpath =
-  let dir =
-    let xdgconfdir = Utils.getenvwithdef "XDG_CONFIG_HOME" E.s in
-    if emptystr xdgconfdir
-    then
-      try
-        let dir = Filename.concat home ".config" in
-        if Sys.is_directory dir then dir else home
-      with _ -> home
-    else xdgconfdir
-  in
-  Filename.concat dir "llpp.conf"
+  Filename.concat home ".llpp.conf"
 ;;
 
 let confpath = ref defconfpath;;

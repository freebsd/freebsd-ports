--- config.ml.orig	2016-11-29 15:11:31 UTC
+++ config.ml
@@ -10,7 +10,7 @@ type fontstate =
 ;;
 
 let fstate =
-  { fontsize = 14
+  { fontsize = 18
   ; wwidth = nan
   ; maxrows = -1
   }
@@ -1461,17 +1461,7 @@ let do_load f contents =
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

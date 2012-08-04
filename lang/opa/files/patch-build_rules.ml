--- tools/build/build_rules.ml.orig	2012-08-01 21:43:40.000000000 -0500
+++ tools/build/build_rules.ml	2012-08-01 21:47:37.000000000 -0500
@@ -452,6 +452,7 @@
        else ".."/dir
      )]
   in
+  let custom_i = [A"--ml";A"-I";A"--ml";A"+site-lib/cryptokit";A"--ml";A"-I";A"--ml";A"+site-lib/ssl";A"--ml";A"-I";A"--ml";A"+site-lib/ssl_threads"] in
   let include_dirs = List.flatten (List.map lib_dir caml_use_lib) in
   let clib s = [A"--ml";A"-cclib";A"--ml";A("-l"^s)] in
   let include_libs = List.flatten (List.map clib c_libs) in
@@ -511,7 +512,8 @@
   let version = get_version_buildinfos () in
   let options = [A"--package-version"; A version; A"-o" ;
     P((Pathname.basename (env opp)))] @ preprocess_js @ preprocess_ml @
-    include_dirs @ include_libs @ js_validation @ files_lib @ options
+    custom_i @ include_dirs @ include_libs @ js_validation @ files_lib @
+    options
   in
   Seq[
     Cmd(S(

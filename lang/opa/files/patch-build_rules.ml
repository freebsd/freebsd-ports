--- build_rules.ml.orig	2012-06-11 14:51:35.000000000 -0500
+++ build_rules.ml	2012-06-11 14:54:06.000000000 -0500
@@ -397,6 +397,7 @@
     |> filter_system_libs
   in
   let lib_dir s = [A"--ml";A"-I";A"--ml";P (if Pathname.exists s then ".." / s else ("+"^s))] in
+  let custom_i = [A"--ml";A"-I";A"--ml";A"+site-lib/cryptokit"] in
   let include_dirs = List.flatten (List.map lib_dir caml_use_lib) in
   let clib s = [A"--ml";A"-cclib";A"--ml";A("-l"^s)] in
   let include_libs = List.flatten (List.map clib c_libs) in
@@ -415,7 +416,7 @@
       unsafe_js @ [A"--js-validator"] @ js_checker @ files_validation
     )
   in
-  let options = [A"--static" ; A"-o" ; P((Pathname.basename (env opp)))] @ include_dirs @ include_libs @js_validation @ files_lib in
+  let options = [A"--static" ; A"-o" ; P((Pathname.basename (env opp)))] @ include_dirs @ custom_i @ include_libs @js_validation @ files_lib in
   Seq[Cmd(S(opa_plugin_builder::options));
       Cmd(S[A"touch"; P(env oppf) ] )]
 in

--- build_rules.ml.orig	2012-01-12 20:08:51.000000000 -0600
+++ build_rules.ml	2012-01-12 20:09:52.000000000 -0600
@@ -374,6 +374,7 @@
   ) (tags_of_pathname (env "%.opa_plugin")) []
   in
   let lib_dir s = [A"--ml";A"-I";A"--ml";P (if Pathname.exists s then ".." / s else ("+"^s))] in
+  let custom_i = [A"--ml";A"-I";A"--ml";A"+site-lib/cryptokit"] in
   let include_dirs = List.flatten (List.map lib_dir caml_use_lib) in
   let files = List.map ((^) path) files in
   build_list build files;
@@ -390,7 +391,7 @@
       unsafe_js @ [A"--js-validator"] @ js_checker @ files_validation
     )
   in
-  let options = [A"--static" ; A"-o" ; P((Pathname.basename (env opp)))] @ include_dirs @ js_validation @ files_lib in
+  let options = [A"--static" ; A"-o" ; P((Pathname.basename (env opp)))] @ include_dirs @ custom_i @ js_validation @ files_lib in
   Seq[Cmd(S(opa_plugin_builder::options));
       Cmd(S[A"touch"; P(env oppf) ] )]
 in

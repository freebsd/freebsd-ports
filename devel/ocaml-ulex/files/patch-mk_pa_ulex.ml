--- mk_pa_ulex.ml.orig	Mon Dec  5 08:30:22 2005
+++ mk_pa_ulex.ml	Mon Dec  5 08:30:33 2005
@@ -1,5 +1,5 @@
 let s = float_of_string (String.sub (Sys.ocaml_version) 0 4) in
-if (s <= 3.09) then (
+if (s < 3.09) then (
   print_endline "Old camlp4 (loc)";
   Sys.command "sed s/_loc/loc/ < pa_ulex.ml.src > pa_ulex.ml"
 )

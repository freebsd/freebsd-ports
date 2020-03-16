--- myocamlbuild.ml.orig	2015-03-17 03:34:14 UTC
+++ myocamlbuild.ml
@@ -1118,13 +1118,13 @@ let package_default =
           (["oasis_library_lacaml_cclib"; "link"],
             [
                (OASISExpr.EBool true,
-                 S [A "-cclib"; A "-lblas"; A "-cclib"; A "-llapack"]);
+                 S [A "-cclib"; A "-L%%LOCALBASE%%/lib"; A "-cclib"; A "%%BLASLIB%%"; A "-cclib"; A "%%LAPACKLIB%%"]);
                (OASISExpr.ETest ("system", "macosx"),
                  S [A "-cclib"; A "-framework"; A "-cclib"; A "Accelerate"])
             ]);
           (["oasis_library_lacaml_cclib"; "ocamlmklib"; "c"],
             [
-               (OASISExpr.EBool true, S [A "-lblas"; A "-llapack"]);
+               (OASISExpr.EBool true, S [A "-L%%LOCALBASE%%/lib"; A "%%BLASLIB%%"; A "%%LAPACKLIB%%"]);
                (OASISExpr.ETest ("system", "macosx"),
                  S [A "-framework"; A "Accelerate"])
             ])

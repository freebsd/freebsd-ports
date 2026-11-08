--- build0.sh.orig	2026-10-25 14:59:44 UTC
+++ build0.sh
@@ -9,7 +9,7 @@ BISON=${BISON:-bison}
 BISON=${BISON:-bison}
 
 # Generate the `version` file (sourced: Windows cannot run the script directly)
-source ci/version.sh
+#source ci/version.sh
 
 # Generate a Fortran AST from AST.asdl (C++)
 python src/libasr/asdl_cpp.py grammar/AST.asdl src/lfortran/ast.h

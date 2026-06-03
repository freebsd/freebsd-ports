--- build0.sh.orig	2026-03-14 14:52:43 UTC
+++ build0.sh
@@ -7,7 +7,7 @@ BISON=${BISON:-bison}
 BISON=${BISON:-bison}
 
 # Generate the `version` file
-ci/version.sh
+#ci/version.sh
 
 # Generate a Fortran AST from AST.asdl (C++)
 python src/libasr/asdl_cpp.py grammar/AST.asdl src/lfortran/ast.h

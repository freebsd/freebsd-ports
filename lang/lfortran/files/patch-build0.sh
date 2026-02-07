--- build0.sh.orig	2025-01-17 18:59:54 UTC
+++ build0.sh
@@ -7,7 +7,7 @@ BISON=${BISON:-bison}
 BISON=${BISON:-bison}
 
 # Generate the `version` file
-ci/version.sh
+#ci/version.sh
 
 # Generate a Fortran AST from AST.asdl (C++)
 python src/libasr/asdl_cpp.py grammar/AST.asdl src/lfortran/ast.h
@@ -21,7 +21,7 @@ python src/libasr/intrinsic_func_registry_util_gen.py
 # Generate the tokenizer and parser
 (cd src/lfortran && ${RE2C} -W -b parser/tokenizer.re -o parser/tokenizer.cpp)
 (cd src/lfortran && ${RE2C} -W -b parser/preprocessor.re -o parser/preprocessor.cpp)
-(cd src/lfortran/parser && ${BISON} -Wall -d -r all parser.yy)
+(cd src/lfortran/parser && ${BISON} -Wall -d -v -r all parser.yy)
 
 grep -n "'" src/lfortran/parser/parser.yy && echo "Single quote not allowed" && exit 1
 echo "OK"

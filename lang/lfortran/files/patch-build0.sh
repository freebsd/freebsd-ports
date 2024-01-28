--- build0.sh.orig	2024-01-28 14:28:08 UTC
+++ build0.sh
@@ -4,7 +4,7 @@ set -x
 set -x
 
 # Generate the `version` file
-ci/version.sh
+#ci/version.sh
 
 # Generate a Fortran AST from AST.asdl (C++)
 python src/libasr/asdl_cpp.py grammar/AST.asdl src/lfortran/ast.h
@@ -18,7 +18,7 @@ python src/libasr/intrinsic_func_registry_util_gen.py
 # Generate the tokenizer and parser
 (cd src/lfortran && re2c -W -b parser/tokenizer.re -o parser/tokenizer.cpp)
 (cd src/lfortran && re2c -W -b parser/preprocessor.re -o parser/preprocessor.cpp)
-(cd src/lfortran/parser && bison -Wall -d -r all parser.yy)
+(cd src/lfortran/parser && bison -Wall -d -v -r all parser.yy)
 
 grep -n "'" src/lfortran/parser/parser.yy && echo "Single quote not allowed" && exit 1
 echo "OK"

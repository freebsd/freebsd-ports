--- build0.sh.orig	2022-11-01 11:12:16 UTC
+++ build0.sh
@@ -4,7 +4,7 @@ set -e
 set -x
 
 # Generate the `version` file
-ci/version.sh
+#ci/version.sh
 
 # Generate a Fortran AST from AST.asdl (C++)
 python src/libasr/asdl_cpp.py grammar/AST.asdl src/lfortran/ast.h
@@ -16,7 +16,7 @@ python src/libasr/wasm_instructions_visitor.py
 # Generate the tokenizer and parser
 (cd src/lfortran/parser && re2c -W -b tokenizer.re -o tokenizer.cpp)
 (cd src/lfortran/parser && re2c -W -b preprocessor.re -o preprocessor.cpp)
-(cd src/lfortran/parser && bison -Wall -d -r all parser.yy)
+(cd src/lfortran/parser && bison -Wall -d -v -r all parser.yy)
 
 grep -n "'" src/lfortran/parser/parser.yy && echo "Single quote not allowed" && exit 1
 echo "OK"

--- config.m4.orig	2014-11-20 06:16:09 UTC
+++ config.m4
@@ -32,11 +32,12 @@ PHP_ARG_ENABLE(jq, whether to enable jq 
 if test "$PHP_JQ" != "no"; then
 
     dnl Source jq
-    PHP_ADD_INCLUDE("jq/")
+    PHP_ADD_INCLUDE("/usr/local/include")
+    PHP_ADD_LIBRARY("jq")
     JQ_SOURCE="jq/locfile.c jq/bytecode.c jq/compile.c jq/execute.c jq/builtin.c jq/jv.c jq/jv_parse.c jq/jv_print.c jq/jv_dtoa.c jq/jv_unicode.c jq/jv_aux.c jq/jv_file.c jq/jv_alloc.c jq/lexer.c jq/parser.c"
 
     dnl PHP Extension
-    PHP_NEW_EXTENSION(jq, jq.c $JQ_SOURCE, $ext_shared)
+    PHP_NEW_EXTENSION(jq, jq.c, $ext_shared)
 fi
 
 dnl coverage

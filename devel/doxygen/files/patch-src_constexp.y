--- src/constexp.y.orig	2021-05-12 18:53:13 UTC
+++ src/constexp.y
@@ -32,7 +32,7 @@ int constexpYYerror(yyscan_t yyscanner, const char *s)
 
 %}
 
-%name-prefix "constexpYY"
+%define api.prefix {constexpYY}
 %define api.pure full
 %lex-param {yyscan_t yyscanner}
 %parse-param {yyscan_t yyscanner}

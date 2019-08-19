--- src/parser.y.orig	2017-10-08 08:53:35 UTC
+++ src/parser.y
@@ -60,7 +60,7 @@ static void reset_parser_vars(void)
  * same range of Bison versions that are supported also
  * by PostgreSQL.
  */
-%name-prefix="plproxy_yy"
+%define api.prefix {plproxy_yy}
 
 %token <str> CONNECT CLUSTER RUN ON ALL ANY SELECT
 %token <str> IDENT NUMBER FNCALL SPLIT STRING

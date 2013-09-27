--- pgsql.c.orig	2010-01-03 10:23:27.000000000 +0100
+++ pgsql.c	2010-03-08 11:00:26.000000000 +0100
@@ -728,7 +731,7 @@
 static int le_link, le_plink, le_result, le_lofp, le_string;
 
 /* {{{ _php_pgsql_trim_message */
-static char * _php_pgsql_trim_message(const char *message, int *len)
+static char * _php_pgsql_trim_message(const char *message, size_t *len)
 {
 	register int i = strlen(message)-1;
 

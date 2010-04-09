--- pgsql.c.orig	2010-01-03 10:23:27.000000000 +0100
+++ pgsql.c	2010-03-08 11:00:26.000000000 +0100
@@ -63,6 +63,7 @@
 #define PGSQL_MAX_LENGTH_OF_LONG   30
 #define PGSQL_MAX_LENGTH_OF_DOUBLE 60
 
+#if UINT_MAX > LONG_MAX
 #define PGSQL_RETURN_OID(oid) do { \
 	if (oid > LONG_MAX) { \
 		smart_str s = {0}; \
@@ -72,7 +73,9 @@
 	} \
 	RETURN_LONG((long)oid); \
 } while(0)
-
+#else
+#define PGSQL_RETURN_OID(oid) RETURN_LONG((long)oid)
+#endif
 
 #if HAVE_PQSETNONBLOCKING
 #define PQ_SETNONBLOCKING(pg_link, flag) PQsetnonblocking(pg_link, flag)
@@ -728,7 +731,7 @@
 static int le_link, le_plink, le_result, le_lofp, le_string;
 
 /* {{{ _php_pgsql_trim_message */
-static char * _php_pgsql_trim_message(const char *message, int *len)
+static char * _php_pgsql_trim_message(const char *message, size_t *len)
 {
 	register int i = strlen(message)-1;
 

--- pgsql.c.orig	2007-10-04 01:31:58.000000000 +0200
+++ pgsql.c	2008-01-29 11:10:15.000000000 +0100
@@ -62,6 +62,7 @@
 #define PGSQL_MAX_LENGTH_OF_LONG   30
 #define PGSQL_MAX_LENGTH_OF_DOUBLE 60
 
+#if UINT_MAX > LONG_MAX
 #define PGSQL_RETURN_OID(oid) do { \
 	if (oid > LONG_MAX) { \
 		smart_str s = {0}; \
@@ -71,7 +72,9 @@
 	} \
 	RETURN_LONG((long)oid); \
 } while(0)
-
+#else
+#define PGSQL_RETURN_OID(oid) RETURN_LONG((long)oid)
+#endif
 
 #if HAVE_PQSETNONBLOCKING
 #define PQ_SETNONBLOCKING(pg_link, flag) PQsetnonblocking(pg_link, flag)
@@ -272,7 +275,7 @@
 static int le_link, le_plink, le_result, le_lofp, le_string;
 
 /* {{{ _php_pgsql_trim_message */
-static char * _php_pgsql_trim_message(const char *message, int *len)
+static char * _php_pgsql_trim_message(const char *message, size_t *len)
 {
 	register int i = strlen(message)-1;
 

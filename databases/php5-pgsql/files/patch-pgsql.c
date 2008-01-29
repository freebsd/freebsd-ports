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
 
@@ -363,7 +366,7 @@
 		if (PGG(log_notices)) {
 			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "%s", notice->message);
 		}
-		zend_hash_index_update(&PGG(notices), (int)resource_id, (void **)&notice, sizeof(php_pgsql_notice *), NULL);
+		zend_hash_index_update(&PGG(notices), (ulong)resource_id, (void **)&notice, sizeof(php_pgsql_notice *), NULL);
 	}
 }
 /* }}} */
@@ -761,13 +764,14 @@
 		 */
 		if (!(connect_type & PGSQL_CONNECT_FORCE_NEW)
 			&& zend_hash_find(&EG(regular_list),str.c,str.len+1,(void **) &index_ptr)==SUCCESS) {
-			int type,link;
+			int type;
+			ulong link;
 			void *ptr;
 
 			if (Z_TYPE_P(index_ptr) != le_index_ptr) {
 				RETURN_FALSE;
 			}
-			link = (int) index_ptr->ptr;
+			link = (uintptr_t /* ulong is as wide or wider than pointer */) index_ptr->ptr;
 			ptr = zend_list_find(link,&type);   /* check if the link is still there */
 			if (ptr && (type==le_link || type==le_plink)) {
 				Z_LVAL_P(return_value) = link;
@@ -1748,12 +1752,15 @@
 
 
 	if (return_oid) {
+#if UINT_MAX > LONG_MAX /* Oid is unsigned int, we don't need this code, where LONG is wider */
 		if (oid > LONG_MAX) {
 			smart_str oidstr = {0};
 			smart_str_append_unsigned(&oidstr, oid);
 			smart_str_0(&oidstr);
 			RETURN_STRINGL(oidstr.c, oidstr.len, 0);
-		} else {
+		} else
+#endif
+		{
 			RETURN_LONG((long)oid);
 		}
 	}
@@ -1854,6 +1861,7 @@
 			
 			oid = PQftype(pgsql_result, Z_LVAL_PP(field));
 
+#if UINT_MAX > LONG_MAX
 			if (oid > LONG_MAX) {
 				smart_str s = {0};
 				smart_str_append_unsigned(&s, oid);
@@ -1863,6 +1871,7 @@
 				Z_TYPE_P(return_value) = IS_STRING;
 			}
 			else
+#endif
 			{
 				Z_LVAL_P(return_value) = (long)oid;
 				Z_TYPE_P(return_value) = IS_LONG;
@@ -5741,8 +5750,8 @@
 {
 	zval *row;
 	char *field_name, *element, *data;
-	size_t num_fields, element_len, data_len;
-	int pg_numrows, pg_row;
+	size_t num_fields, element_len;
+	int pg_numrows, pg_row, data_len;
 	uint i;
 	assert(Z_TYPE_P(ret_array) == IS_ARRAY);
 

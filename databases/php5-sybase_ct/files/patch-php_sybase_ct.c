--- php_sybase_ct.c.orig	Mon Dec 12 23:04:09 2005
+++ php_sybase_ct.c	Mon Dec 12 23:05:24 2005
@@ -467,8 +467,8 @@
 static int php_sybase_do_connect_internal(sybase_link *sybase, char *host, char *user, char *passwd, char *charset, char *appname)
 {
 	CS_LOCALE *tmp_locale;
-	TSRMLS_FETCH();
 	long packetsize;
+	TSRMLS_FETCH();
 
 	/* set a CS_CONNECTION record */
 	if (ct_con_alloc(SybCtG(context), &sybase->connection)!=CS_SUCCEED) {

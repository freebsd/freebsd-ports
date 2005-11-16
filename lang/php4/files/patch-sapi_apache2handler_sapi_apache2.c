--- sapi/apache2handler/sapi_apache2.c.orig	Wed Oct 12 23:41:36 2005
+++ sapi/apache2handler/sapi_apache2.c	Tue Nov 15 23:27:16 2005
@@ -453,34 +453,15 @@
 	request_rec *parent_req = NULL;
 	TSRMLS_FETCH();
 
-#define PHPAP_INI_OFF \
-	if (strcmp(r->protocol, "INCLUDED")) { \
-		zend_try { zend_ini_deactivate(TSRMLS_C); } zend_end_try(); \
-	} \
-
 	conf = ap_get_module_config(r->per_dir_config, &php4_module);
-
-	/* apply_config() needs r in some cases, so allocate server_context early */
-	ctx = SG(server_context);
-	if (ctx == NULL) {
-		ctx = SG(server_context) = apr_pcalloc(r->pool, sizeof(*ctx));
-		/* register a cleanup so we clear out the SG(server_context)
-		 * after each request. Note: We pass in the pointer to the
-		 * server_context in case this is handled by a different thread.
-		 */
-		apr_pool_cleanup_register(r->pool, (void *)&SG(server_context), php_server_context_cleanup, apr_pool_cleanup_null);
-		ctx->r = r;
-		ctx = NULL; /* May look weird to null it here, but it is to catch the right case in the first_try later on */
-	} else {
-		parent_req = ctx->r;
-		ctx->r = r;
-	}
 	apply_config(conf);
 
 	if (strcmp(r->handler, PHP_MAGIC_TYPE) && strcmp(r->handler, PHP_SOURCE_MAGIC_TYPE) && strcmp(r->handler, PHP_SCRIPT)) {
 		/* Check for xbithack in this case. */
 		if (!AP2(xbithack) || strcmp(r->handler, "text/html") || !(r->finfo.protection & APR_UEXECUTE)) {
-			PHPAP_INI_OFF;
+			zend_try {
+				zend_ini_deactivate(TSRMLS_C);
+			} zend_end_try();
 			return DECLINED;
 		}
 	}
@@ -489,24 +470,32 @@
 	 * the configuration; default behaviour is to accept. */ 
 	if (r->used_path_info == AP_REQ_REJECT_PATH_INFO
 		&& r->path_info && r->path_info[0]) {
-		PHPAP_INI_OFF;
+		zend_try {
+			zend_ini_deactivate(TSRMLS_C);
+		} zend_end_try();
 		return HTTP_NOT_FOUND;
 	}
 
 	/* handle situations where user turns the engine off */
 	if (!AP2(engine)) {
-		PHPAP_INI_OFF;
+		zend_try {
+			zend_ini_deactivate(TSRMLS_C);
+		} zend_end_try();
 		return DECLINED;
 	}
 
 	if (r->finfo.filetype == 0) {
 		php_apache_sapi_log_message_ex("script '%s' not found or unable to stat", r);
-		PHPAP_INI_OFF;
+		zend_try {
+				zend_ini_deactivate(TSRMLS_C);
+		} zend_end_try();
 		return HTTP_NOT_FOUND;
 	}
 	if (r->finfo.filetype == APR_DIR) {
 		php_apache_sapi_log_message_ex("attempt to invoke directory '%s' as script", r);
-		PHPAP_INI_OFF;
+		zend_try {
+			zend_ini_deactivate(TSRMLS_C);
+		} zend_end_try();
 		return HTTP_FORBIDDEN;
 	}
 
@@ -522,30 +511,24 @@
 
 zend_first_try {
 
+	ctx = SG(server_context);
 	if (ctx == NULL) {
-normal:
+		ctx = SG(server_context) = apr_pcalloc(r->pool, sizeof(*ctx));
+		/* register a cleanup so we clear out the SG(server_context)
+		 * after each request. Note: We pass in the pointer to the
+		 * server_context in case this is handled by a different thread.
+		 */
+		apr_pool_cleanup_register(r->pool, (void *)&SG(server_context), php_server_context_cleanup, apr_pool_cleanup_null);
+
+		ctx->r = r;
 		brigade = apr_brigade_create(r->pool, r->connection->bucket_alloc);
-		ctx = SG(server_context);
 		ctx->brigade = brigade;
 
 		if (php_apache_request_ctor(r, ctx TSRMLS_CC)!=SUCCESS) {
 			zend_bailout();
 		}
 	} else {
-		if (!parent_req) {
-			parent_req = ctx->r;
-		}
-		if (parent_req && strcmp(parent_req->handler, PHP_MAGIC_TYPE) && strcmp(parent_req->handler, PHP_SOURCE_MAGIC_TYPE) && strcmp(parent_req->handler, PHP_SCRIPT)) {
-			if (php_apache_request_ctor(r, ctx TSRMLS_CC)!=SUCCESS) {
-				zend_bailout();
-			}
-		}
-		
-		/* check if comming due to ErrorDocument */
-		if (parent_req && parent_req->status != HTTP_OK) {
-			parent_req = NULL;
-			goto normal;
-		}
+		parent_req = ctx->r;
 		ctx->r = r;
 		brigade = ctx->brigade;
 	}

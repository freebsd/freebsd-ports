--- main/main.c.orig	2026-10-21 15:33:56 UTC
+++ main/main.c
@@ -1847,6 +1847,8 @@ void php_request_shutdown(void *dummy)
 
 		for (i=0; i<NUM_TRACK_VARS; i++) {
 			zval_ptr_dtor(&PG(http_globals)[i]);
+			/* May be accessed before php_request_startup() */
+			ZVAL_UNDEF(&PG(http_globals)[i]);
 		}
 	} zend_end_try();
 
@@ -1878,6 +1880,7 @@ void php_request_shutdown(void *dummy)
 
 	/* 15. Free Willy (here be crashes) */
 	zend_interned_strings_deactivate();
+	clear_last_error();
 	zend_try {
 		shutdown_memory_manager(CG(unclean_shutdown) || !report_memleaks, 0);
 	} zend_end_try();
@@ -1901,6 +1904,9 @@ void php_request_shutdown(void *dummy)
 #ifdef HAVE_DTRACE
 	DTRACE_REQUEST_SHUTDOWN(SAFE_FILENAME(SG(request_info).path_translated), SAFE_FILENAME(SG(request_info).request_uri), (char *)SAFE_FILENAME(SG(request_info).request_method));
 #endif /* HAVE_DTRACE */
+
+	/* May be accessed before php_request_startup() */
+	PG(modules_activated) = 0;
 }
 /* }}} */
 

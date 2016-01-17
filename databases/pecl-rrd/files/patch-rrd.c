--- rrd.c.orig	2016-01-12 12:42:39 UTC
+++ rrd.c
@@ -19,7 +19,9 @@
 #include <rrd.h>
 
 #include "php_rrd.h"
+#ifdef HAVE_RRD_GRAPH
 #include "rrd_graph.h"
+#endif
 #include "rrd_create.h"
 #include "rrd_update.h"
 #include "rrd_info.h"
@@ -387,6 +389,7 @@ PHP_FUNCTION(rrd_tune)
 }
 /* }}} */
 
+#ifdef HAVE_RRD_GRAPH
 /* {{{ proto array rrd_xport(array options)
  * Creates a graph based on options passed via an array
  */
@@ -480,6 +483,7 @@ PHP_FUNCTION(rrd_xport)
 	free(data);
 }
 /* }}} */
+#endif
 
 #ifdef HAVE_RRDC_DISCONNECT
 /* {{{ proto void rrdc_disconnect()
@@ -537,18 +541,22 @@ ZEND_BEGIN_ARG_INFO(arginfo_rrd_tune, 0)
 	ZEND_ARG_INFO(0, options)
 ZEND_END_ARG_INFO()
 
+#ifdef HAVE_RRD_GRAPH
 ZEND_BEGIN_ARG_INFO(arginfo_rrd_xport, 0)
 	ZEND_ARG_INFO(0, options)
 ZEND_END_ARG_INFO()
+#endif
 
 ZEND_BEGIN_ARG_INFO(arginfo_rrd_info, 0)
 	ZEND_ARG_INFO(0, file)
 ZEND_END_ARG_INFO()
 
+#ifdef HAVE_RRD_GRAPH
 ZEND_BEGIN_ARG_INFO(arginfo_rrd_graph, 0)
 	ZEND_ARG_INFO(0, file)
 	ZEND_ARG_INFO(0, options)
 ZEND_END_ARG_INFO()
+#endif
 
 ZEND_BEGIN_ARG_INFO(arginfo_rrd_create, 0)
 	ZEND_ARG_INFO(0, filename)
@@ -565,7 +573,9 @@ ZEND_END_ARG_INFO()
 static zend_function_entry rrd_functions[] = {
 	PHP_FE(rrd_update, arginfo_rrd_update)
 	PHP_FE(rrd_create, arginfo_rrd_create)
+#ifdef HAVE_RRD_GRAPH
 	PHP_FE(rrd_graph, arginfo_rrd_graph)
+#endif
 	PHP_FE(rrd_error, NULL)
 	PHP_FE(rrd_fetch, arginfo_rrd_fetch)
 	PHP_FE(rrd_first, arginfo_rrd_first)
@@ -574,7 +584,9 @@ static zend_function_entry rrd_functions
 	PHP_FE(rrd_lastupdate, arginfo_rrd_lastupdate)
 	PHP_FE(rrd_restore, arginfo_rrd_restore)
 	PHP_FE(rrd_tune, arginfo_rrd_tune)
+#ifdef HAVE_RRD_GRAPH
 	PHP_FE(rrd_xport, arginfo_rrd_xport)
+#endif
 #ifdef HAVE_RRDC_DISCONNECT
 	PHP_FE(rrdc_disconnect, NULL)
 #endif
@@ -590,7 +602,9 @@ static zend_function_entry rrd_functions
 /* {{{ PHP_MINIT_FUNCTION */
 static PHP_MINIT_FUNCTION(rrd)
 {
+#ifdef HAVE_RRD_GRAPH
 	rrd_graph_minit(TSRMLS_C);
+#endif
 	rrd_create_minit(TSRMLS_C);
 	rrd_update_minit(TSRMLS_C);
 	return SUCCESS;

--- php_zookeeper.c.orig	2019-12-11 01:31:04 UTC
+++ php_zookeeper.c
@@ -772,7 +772,6 @@ static PHP_METHOD(Zookeeper, dispatch)
 }
 /* }}} */
 
-#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
 /* {{{ Zookeeper::getConfig( .. )
    */
 static PHP_METHOD(Zookeeper, getConfig)
@@ -788,7 +787,6 @@ static PHP_METHOD(Zookeeper, getConfig)
 	RETURN_OBJ(php_zk_config_new_from_zk(php_zk_config_ce, i_obj));
 }
 /* }}} */
-#endif
 
 PHP_FUNCTION(zookeeper_dispatch)
 {
@@ -1250,10 +1248,8 @@ ZEND_END_ARG_INFO()
 ZEND_BEGIN_ARG_INFO(arginfo_dispatch, 0)
 ZEND_END_ARG_INFO()
 
-#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
 ZEND_BEGIN_ARG_INFO(arginfo_getConfig, 0)
 ZEND_END_ARG_INFO()
-#endif
 /* }}} */
 
 /* {{{ zookeeper_class_methods */
@@ -1290,9 +1286,7 @@ static zend_function_entry zookeeper_class_methods[] =
 
 	ZK_ME_STATIC(dispatch,    arginfo_dispatch)
 
-#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
 	ZK_ME(getConfig,          arginfo_getConfig)
-#endif
 
 	PHP_FE_END
 };
@@ -1381,10 +1375,8 @@ static void php_zk_register_constants(INIT_FUNC_ARGS)
 	ZK_CLASS_CONST_LONG2(OPERATIONTIMEOUT);
 	ZK_CLASS_CONST_LONG2(BADARGUMENTS);
 	ZK_CLASS_CONST_LONG2(INVALIDSTATE);
-#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
 	ZK_CLASS_CONST_LONG2(NEWCONFIGNOQUORUM);
 	ZK_CLASS_CONST_LONG2(RECONFIGINPROGRESS);
-#endif
 
 	ZK_CLASS_CONST_LONG2(OK);
 	ZK_CLASS_CONST_LONG2(APIERROR);
@@ -1463,9 +1455,7 @@ PHP_MINIT_FUNCTION(zookeeper)
 
 	php_zk_register_exceptions(TSRMLS_C);
 
-#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
 	php_zk_config_register(TSRMLS_C);
-#endif
 
 #if PHP_MAJOR_VERSION >= 7 && PHP_MINOR_VERSION >= 1
 	orig_interrupt_function = zend_interrupt_function;
@@ -1537,7 +1527,11 @@ PHP_MINFO_FUNCTION(zookeeper)
 	php_info_print_table_header(2, "zookeeper support", "enabled");
 	php_info_print_table_row(2, "version", PHP_ZOOKEEPER_VERSION);
 
+#if defined(ZOO_VERSION)
+	snprintf(buf, sizeof(buf), "%s", ZOO_VERSION);
+#else
 	snprintf(buf, sizeof(buf), "%ld.%ld.%ld", ZOO_MAJOR_VERSION, ZOO_MINOR_VERSION, ZOO_PATCH_VERSION);
+#endif
 	php_info_print_table_row(2, "libzookeeper version", buf);
 
 	php_info_print_table_end();

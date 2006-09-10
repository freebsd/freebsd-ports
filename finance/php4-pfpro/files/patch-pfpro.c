--- pfpro.c.orig	Sun Sep 10 18:20:52 2006
+++ pfpro.c	Sun Sep 10 18:24:07 2006
@@ -80,6 +80,7 @@
 	STD_PHP_INI_ENTRY("pfpro.proxyport",      "",    PHP_INI_ALL, OnUpdateInt,    proxyport,      zend_pfpro_globals, pfpro_globals)
 	STD_PHP_INI_ENTRY("pfpro.proxylogon",     "",    PHP_INI_ALL, OnUpdateString, proxylogon,     zend_pfpro_globals, pfpro_globals)
 	STD_PHP_INI_ENTRY("pfpro.proxypassword",  "",    PHP_INI_ALL, OnUpdateString, proxypassword,  zend_pfpro_globals, pfpro_globals)
+	STD_PHP_INI_ENTRY("pfpro.certpath", "%%LOCALBASE%%/etc/pfpro/certs", PHP_INI_ALL, OnUpdateString, certpath, zend_pfpro_globals, pfpro_globals)
 PHP_INI_END()
 
 /* {{{ php_extname_init_globals
@@ -94,6 +95,7 @@
 	pfpro_globals->proxyport      = 0;
 	pfpro_globals->proxylogon     = NULL;
 	pfpro_globals->proxypassword  = NULL;
+	pfpro_globals->certpath       = NULL;
 }
 /* }}} */
 
@@ -133,6 +135,7 @@
 	php_info_print_table_start();
 	php_info_print_table_row(2, "Verisign Payflow Pro support", "enabled");
 	php_info_print_table_row(2, "libpfpro version", pfproVersion());
+	php_info_print_table_row(2, "pfpro.certpath", PFPROG(certpath));
 	php_info_print_table_end();
 
 	DISPLAY_INI_ENTRIES();
@@ -158,6 +161,8 @@
 	if (ZEND_NUM_ARGS() != 0) {
 		WRONG_PARAM_COUNT;
 	}
+
+	setenv("PFPRO_CERT_PATH", PFPROG(certpath), 0);
 
 	pfproInit();
 

--- ./php_spread.c.orig	2010-04-13 08:58:25.000000000 -0400
+++ ./php_spread.c	2010-04-13 08:59:06.000000000 -0400
@@ -45,7 +45,6 @@
 static int le_conn;
 
 /* {{{ arginfo */
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_spread_connect, 0, 0, 1)
 	ZEND_ARG_INFO(0, spread_daemon)
 	ZEND_ARG_INFO(0, private_name)

--- ./msgformat/msgformat_class.c.orig	2010-04-13 10:35:58.000000000 -0400
+++ ./msgformat/msgformat_class.c	2010-04-13 10:36:15.000000000 -0400
@@ -77,34 +77,28 @@
  */
 
 /* {{{ arginfo */
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_messageformatter___construct, 0, 0, 2)
 	ZEND_ARG_INFO(0, locale)
 	ZEND_ARG_INFO(0, pattern)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO(arginfo_messageformatter_geterrormessage, 0)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_messageformatter_formatmessage, 0, 0, 3)
 	ZEND_ARG_INFO(0, locale)
 	ZEND_ARG_INFO(0, pattern)
 	ZEND_ARG_INFO(0, args)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_messageformatter_format, 0, 0, 1)
 	ZEND_ARG_INFO(0, args)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_messageformatter_setpattern, 0, 0, 1)
 	ZEND_ARG_INFO(0, pattern)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_messageformatter_parse, 0, 0, 1)
 	ZEND_ARG_INFO(0, source)
 ZEND_END_ARG_INFO()

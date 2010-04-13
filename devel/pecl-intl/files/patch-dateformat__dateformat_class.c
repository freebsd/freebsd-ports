--- ./dateformat/dateformat_class.c.orig	2010-04-13 10:34:55.000000000 -0400
+++ ./dateformat/dateformat_class.c	2010-04-13 10:35:14.000000000 -0400
@@ -84,42 +84,35 @@
  */
 
 /* {{{ arginfo */
-static ZEND_BEGIN_ARG_INFO_EX(datefmt_parse_args, 0, 0, 1)
+ZEND_BEGIN_ARG_INFO_EX(datefmt_parse_args, 0, 0, 1)
 		ZEND_ARG_INFO(0, string)
 		ZEND_ARG_INFO(1, position)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_intldateformatter_format, 0, 0, 0)
 	ZEND_ARG_INFO(0, args)
 	ZEND_ARG_INFO(0, array)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO(arginfo_intldateformatter_getdatetype, 0)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_intldateformatter_settimezoneid, 0, 0, 1)
 	ZEND_ARG_INFO(0, zone)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_intldateformatter_setpattern, 0, 0, 1)
 	ZEND_ARG_INFO(0, pattern)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_intldateformatter_setlenient, 0, 0, 1)
 	ZEND_ARG_INFO(0, lenient)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_intldateformatter_setcalendar, 0, 0, 1)
 	ZEND_ARG_INFO(0, which)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_intldateformatter___construct, 0, 0, 3)
 	ZEND_ARG_INFO(0, locale)
 	ZEND_ARG_INFO(0, datetype)

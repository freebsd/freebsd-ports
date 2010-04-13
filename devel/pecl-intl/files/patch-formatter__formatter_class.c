--- ./formatter/formatter_class.c.orig	2010-03-15 18:03:30.000000000 -0400
+++ ./formatter/formatter_class.c	2010-04-13 10:31:54.000000000 -0400
@@ -80,63 +80,54 @@
  */
 
 /* {{{ arginfo */
-static ZEND_BEGIN_ARG_INFO_EX(number_parse_arginfo, 0, 0, 1)
+ZEND_BEGIN_ARG_INFO_EX(number_parse_arginfo, 0, 0, 1)
 	ZEND_ARG_INFO(0, string)
 	ZEND_ARG_INFO(0, type)
 	ZEND_ARG_INFO(1, position)
 ZEND_END_ARG_INFO()
 
-static ZEND_BEGIN_ARG_INFO_EX(number_parse_currency_arginfo, 0, 0, 2)
+ZEND_BEGIN_ARG_INFO_EX(number_parse_currency_arginfo, 0, 0, 2)
 	ZEND_ARG_INFO(0, string)
 	ZEND_ARG_INFO(1, currency)
 	ZEND_ARG_INFO(1, position)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_numberformatter_getattribute, 0, 0, 1)
 	ZEND_ARG_INFO(0, attr)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_numberformatter_setattribute, 0, 0, 2)
 	ZEND_ARG_INFO(0, attr)
 	ZEND_ARG_INFO(0, value)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_numberformatter_setsymbol, 0, 0, 2)
 	ZEND_ARG_INFO(0, attr)
 	ZEND_ARG_INFO(0, symbol)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO(arginfo_numberformatter_getpattern, 0)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_numberformatter_setpattern, 0, 0, 1)
 	ZEND_ARG_INFO(0, pattern)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_numberformatter_getlocale, 0, 0, 0)
 	ZEND_ARG_INFO(0, type)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_numberformatter___construct, 0, 0, 2)
 	ZEND_ARG_INFO(0, locale)
 	ZEND_ARG_INFO(0, style)
 	ZEND_ARG_INFO(0, pattern)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_numberformatter_formatcurrency, 0, 0, 2)
 	ZEND_ARG_INFO(0, num)
 	ZEND_ARG_INFO(0, currency)
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX(arginfo_numberformatter_format, 0, 0, 1)
 	ZEND_ARG_INFO(0, num)
 	ZEND_ARG_INFO(0, type)

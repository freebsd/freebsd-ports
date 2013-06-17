--- php/src/IcePHP/Init.cpp.orig	2013-03-11 15:19:47.000000000 +0000
+++ php/src/IcePHP/Init.cpp	2013-06-02 11:44:16.052196522 +0000
@@ -22,10 +22,10 @@
 
 ZEND_DECLARE_MODULE_GLOBALS(ice)
 
-ZEND_BEGIN_ARG_INFO(Ice_initialize_arginfo, 1)
+ZEND_BEGIN_ARG_INFO_EX(Ice_initialize_arginfo, 1, ZEND_RETURN_VALUE, static_cast<zend_uint>(-1))
 ZEND_END_ARG_INFO()
 
-ZEND_BEGIN_ARG_INFO(Ice_createProperties_arginfo, 1)
+ZEND_BEGIN_ARG_INFO_EX(Ice_createProperties_arginfo, 1, ZEND_RETURN_VALUE, static_cast<zend_uint>(-1))
 ZEND_END_ARG_INFO()
 
 #define ICEPHP_COMMUNICATOR_FUNCTIONS \

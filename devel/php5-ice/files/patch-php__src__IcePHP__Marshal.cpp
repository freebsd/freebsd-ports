--- ./php/src/IcePHP/Marshal.cpp.orig	2010-04-13 11:43:37.000000000 -0400
+++ ./php/src/IcePHP/Marshal.cpp	2010-04-13 11:43:44.000000000 -0400
@@ -1929,7 +1929,7 @@
     this->TSRMLS_C = TSRMLS_C;
 #endif
 
-    ZVAL_ADDREF(_value);
+    Z_ADDREF_P(_value);
 
     _class = Z_OBJCE_P(_value);
 }

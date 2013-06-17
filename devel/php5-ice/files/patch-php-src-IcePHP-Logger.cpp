--- php/src/IcePHP/Logger.cpp.orig	2013-06-02 11:52:25.727195546 +0000
+++ php/src/IcePHP/Logger.cpp	2013-06-02 11:52:39.876195038 +0000
@@ -269,7 +269,7 @@
     //
     zend_class_entry ce;
 #ifdef ICEPHP_USE_NAMESPACES
-    INIT_NS_CLASS_ENTRY(ce, STRCAST("Ice"), STRCAST("Logger"), _interfaceMethods);
+    INIT_NS_CLASS_ENTRY(ce, "Ice", "Logger", _interfaceMethods);
 #else
     INIT_CLASS_ENTRY(ce, "Ice_Logger", _interfaceMethods);
 #endif

--- php/src/IcePHP/Properties.cpp.orig	2013-06-02 11:52:55.531198249 +0000
+++ php/src/IcePHP/Properties.cpp	2013-06-02 11:53:07.786227648 +0000
@@ -641,7 +641,7 @@
     //
     zend_class_entry ce;
 #ifdef ICEPHP_USE_NAMESPACES
-    INIT_NS_CLASS_ENTRY(ce, STRCAST("Ice"), STRCAST("Properties"), _interfaceMethods);
+    INIT_NS_CLASS_ENTRY(ce, "Ice", "Properties", _interfaceMethods);
 #else
     INIT_CLASS_ENTRY(ce, "Ice_Properties", _interfaceMethods);
 #endif

--- php/src/IcePHP/Proxy.cpp.orig	2013-06-02 11:54:02.594196824 +0000
+++ php/src/IcePHP/Proxy.cpp	2013-06-02 11:53:46.793198453 +0000
@@ -1702,7 +1702,7 @@
     //
     zend_class_entry ce;
 #ifdef ICEPHP_USE_NAMESPACES
-    INIT_NS_CLASS_ENTRY(ce, STRCAST("Ice"), STRCAST("ObjectPrx"), _proxyMethods);
+    INIT_NS_CLASS_ENTRY(ce, "Ice", "ObjectPrx", _proxyMethods);
 #else
     INIT_CLASS_ENTRY(ce, "Ice_ObjectPrx", _proxyMethods);
 #endif

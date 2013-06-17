--- php/src/IcePHP/Communicator.cpp.orig	2013-06-02 11:48:21.990197196 +0000
+++ php/src/IcePHP/Communicator.cpp	2013-06-02 11:48:29.692195174 +0000
@@ -1341,7 +1341,7 @@
     //
     zend_class_entry ce;
 #ifdef ICEPHP_USE_NAMESPACES
-    INIT_NS_CLASS_ENTRY(ce, STRCAST("Ice"), STRCAST("Communicator"), _interfaceMethods);
+    INIT_NS_CLASS_ENTRY(ce, "Ice", "Communicator", _interfaceMethods);
 #else
     INIT_CLASS_ENTRY(ce, "Ice_Communicator", _interfaceMethods);
 #endif

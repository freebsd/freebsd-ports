--- php/src/IcePHP/Endpoint.cpp.orig	2013-06-02 11:51:19.569193334 +0000
+++ php/src/IcePHP/Endpoint.cpp	2013-06-02 11:52:06.348197336 +0000
@@ -274,7 +274,7 @@
     //
     zend_class_entry ce;
 #ifdef ICEPHP_USE_NAMESPACES
-    INIT_NS_CLASS_ENTRY(ce, STRCAST("Ice"), STRCAST("Endpoint"), _interfaceMethods);
+    INIT_NS_CLASS_ENTRY(ce, "Ice", "Endpoint", _interfaceMethods);
 #else
     INIT_CLASS_ENTRY(ce, "Ice_Endpoint", _interfaceMethods);
 #endif
@@ -293,7 +293,7 @@
     // Register the EndpointInfo class.
     //
 #ifdef ICEPHP_USE_NAMESPACES
-    INIT_NS_CLASS_ENTRY(ce, STRCAST("Ice"), STRCAST("EndpointInfo"), _endpointInfoMethods);
+    INIT_NS_CLASS_ENTRY(ce, "Ice", "EndpointInfo", _endpointInfoMethods);
 #else
     INIT_CLASS_ENTRY(ce, "Ice_EndpointInfo", _endpointInfoMethods);
 #endif
@@ -309,7 +309,7 @@
     // Register the IPEndpointInfo class.
     //
 #ifdef ICEPHP_USE_NAMESPACES
-    INIT_NS_CLASS_ENTRY(ce, STRCAST("Ice"), STRCAST("IPEndpointInfo"), NULL);
+    INIT_NS_CLASS_ENTRY(ce, "Ice", "IPEndpointInfo", NULL);
 #else
     INIT_CLASS_ENTRY(ce, "Ice_IPEndpointInfo", NULL);
 #endif
@@ -324,7 +324,7 @@
     // Register the TCPEndpointInfo class.
     //
 #ifdef ICEPHP_USE_NAMESPACES
-    INIT_NS_CLASS_ENTRY(ce, STRCAST("Ice"), STRCAST("TCPEndpointInfo"), NULL);
+    INIT_NS_CLASS_ENTRY(ce, "Ice", "TCPEndpointInfo", NULL);
 #else
     INIT_CLASS_ENTRY(ce, "Ice_TCPEndpointInfo", NULL);
 #endif
@@ -335,7 +335,7 @@
     // Register the UDPEndpointInfo class.
     //
 #ifdef ICEPHP_USE_NAMESPACES
-    INIT_NS_CLASS_ENTRY(ce, STRCAST("Ice"), STRCAST("UDPEndpointInfo"), NULL);
+    INIT_NS_CLASS_ENTRY(ce, "Ice", "UDPEndpointInfo", NULL);
 #else
     INIT_CLASS_ENTRY(ce, "Ice_UDPEndpointInfo", NULL);
 #endif
@@ -350,7 +350,7 @@
     // Register the OpaqueEndpointInfo class.
     //
 #ifdef ICEPHP_USE_NAMESPACES
-    INIT_NS_CLASS_ENTRY(ce, STRCAST("Ice"), STRCAST("OpaqueEndpointInfo"), NULL);
+    INIT_NS_CLASS_ENTRY(ce, "Ice", "OpaqueEndpointInfo", NULL);
 #else
     INIT_CLASS_ENTRY(ce, "Ice_OpaqueEndpointInfo", NULL);
 #endif

--- php/src/IcePHP/Connection.cpp.orig	2013-06-02 11:48:58.022196354 +0000
+++ php/src/IcePHP/Connection.cpp	2013-06-02 11:50:59.494195380 +0000
@@ -360,7 +360,7 @@
     //
     zend_class_entry ce;
 #ifdef ICEPHP_USE_NAMESPACES
-    INIT_NS_CLASS_ENTRY(ce, STRCAST("Ice"), STRCAST("Connection"), _interfaceMethods);
+    INIT_NS_CLASS_ENTRY(ce, "Ice", "Connection", _interfaceMethods);
 #else
     INIT_CLASS_ENTRY(ce, "Ice_Connection", _interfaceMethods);
 #endif
@@ -380,7 +380,7 @@
     // Register the ConnectionInfo class.
     //
 #ifdef ICEPHP_USE_NAMESPACES
-    INIT_NS_CLASS_ENTRY(ce, STRCAST("Ice"), STRCAST("ConnectionInfo"), _connectionInfoClassMethods);
+    INIT_NS_CLASS_ENTRY(ce, "Ice", "ConnectionInfo", _connectionInfoClassMethods);
 #else
     INIT_CLASS_ENTRY(ce, "Ice_ConnectionInfo", _connectionInfoClassMethods);
 #endif
@@ -396,7 +396,7 @@
     // Register the IPConnectionInfo class.
     //
 #ifdef ICEPHP_USE_NAMESPACES
-    INIT_NS_CLASS_ENTRY(ce, STRCAST("Ice"), STRCAST("IPConnectionInfo"), NULL);
+    INIT_NS_CLASS_ENTRY(ce, "Ice", "IPConnectionInfo", NULL);
 #else
     INIT_CLASS_ENTRY(ce, "Ice_IPConnectionInfo", NULL);
 #endif
@@ -415,7 +415,7 @@
     // Register the TCPConnectionInfo class.
     //
 #ifdef ICEPHP_USE_NAMESPACES
-    INIT_NS_CLASS_ENTRY(ce, STRCAST("Ice"), STRCAST("TCPConnectionInfo"), NULL);
+    INIT_NS_CLASS_ENTRY(ce, "Ice", "TCPConnectionInfo", NULL);
 #else
     INIT_CLASS_ENTRY(ce, "Ice_TCPConnectionInfo", NULL);
 #endif
@@ -426,7 +426,7 @@
     // Register the UDPConnectionInfo class.
     //
 #ifdef ICEPHP_USE_NAMESPACES
-    INIT_NS_CLASS_ENTRY(ce, STRCAST("Ice"), STRCAST("UDPConnectionInfo"), NULL);
+    INIT_NS_CLASS_ENTRY(ce, "Ice", "UDPConnectionInfo", NULL);
 #else
     INIT_CLASS_ENTRY(ce, "Ice_UDPConnectionInfo", NULL);
 #endif

--- dbus/dbus-protocol.h.orig	2012-09-08 10:15:17.000000000 +0200
+++ dbus/dbus-protocol.h	2012-09-08 10:16:12.000000000 +0200
@@ -456,7 +456,7 @@
 /** XML system identifier of the introspection format version 1.0 */
 #define DBUS_INTROSPECT_1_0_XML_SYSTEM_IDENTIFIER "http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd"
 /** XML document type declaration of the introspection format version 1.0 */
-#define DBUS_INTROSPECT_1_0_XML_DOCTYPE_DECL_NODE "<!DOCTYPE node PUBLIC \""DBUS_INTROSPECT_1_0_XML_PUBLIC_IDENTIFIER"\"\n\""DBUS_INTROSPECT_1_0_XML_SYSTEM_IDENTIFIER"\">\n"
+#define DBUS_INTROSPECT_1_0_XML_DOCTYPE_DECL_NODE "<!DOCTYPE node PUBLIC \"" DBUS_INTROSPECT_1_0_XML_PUBLIC_IDENTIFIER "\"\n\"" DBUS_INTROSPECT_1_0_XML_SYSTEM_IDENTIFIER "\">\n"
 
 /** @} */
 

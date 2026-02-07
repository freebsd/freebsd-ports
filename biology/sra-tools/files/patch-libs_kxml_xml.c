--- libs/kxml/xml.c.orig	2025-12-03 13:29:03 UTC
+++ libs/kxml/xml.c
@@ -171,7 +171,7 @@ rc_t KXMLMgrSchemaValidate ( const KXMLMgr *self,
 }
 #endif
 
-static void s_xmlGenericErrorDefaultFunc(void *ctx ATTRIBUTE_UNUSED,
+static void s_xmlGenericErrorDefaultFunc(void *ctx,
     const char *msg,
     ...)
 {

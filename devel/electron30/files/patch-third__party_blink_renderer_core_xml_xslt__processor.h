--- third_party/blink/renderer/core/xml/xslt_processor.h.orig	2024-02-21 00:20:54 UTC
+++ third_party/blink/renderer/core/xml/xslt_processor.h
@@ -77,7 +77,11 @@ class XSLTProcessor final : public ScriptWrappable {
 
   void reset();
 
+#if (LIBXML_VERSION >= 21200)
   static void ParseErrorFunc(void* user_data, const xmlError*);
+#else
+  static void ParseErrorFunc(void* user_data, xmlError*);
+#endif
   static void GenericErrorFunc(void* user_data, const char* msg, ...);
 
   // Only for libXSLT callbacks

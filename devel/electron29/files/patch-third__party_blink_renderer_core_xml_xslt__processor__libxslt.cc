--- third_party/blink/renderer/core/xml/xslt_processor_libxslt.cc.orig	2024-02-21 00:20:54 UTC
+++ third_party/blink/renderer/core/xml/xslt_processor_libxslt.cc
@@ -66,7 +66,11 @@ void XSLTProcessor::GenericErrorFunc(void*, const char
   // It would be nice to do something with this error message.
 }
 
+#if (LIBXML_VERSION >= 21200)
 void XSLTProcessor::ParseErrorFunc(void* user_data, const xmlError* error) {
+#else
+void XSLTProcessor::ParseErrorFunc(void* user_data, xmlError* error) {
+#endif
   FrameConsole* console = static_cast<FrameConsole*>(user_data);
   if (!console)
     return;

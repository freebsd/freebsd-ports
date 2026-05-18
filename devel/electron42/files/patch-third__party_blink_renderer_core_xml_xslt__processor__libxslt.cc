--- third_party/blink/renderer/core/xml/xslt_processor_libxslt.cc.orig	2025-03-24 20:50:14 UTC
+++ third_party/blink/renderer/core/xml/xslt_processor_libxslt.cc
@@ -68,7 +68,11 @@ void XSLTProcessor::GenericErrorFunc(void*, const char
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

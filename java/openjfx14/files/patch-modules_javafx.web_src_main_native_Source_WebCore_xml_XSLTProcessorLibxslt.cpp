--- modules/javafx.web/src/main/native/Source/WebCore/xml/XSLTProcessorLibxslt.cpp.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/WebCore/xml/XSLTProcessorLibxslt.cpp
@@ -60,7 +60,11 @@ void XSLTProcessor::genericErrorFunc(void*, const char
     // It would be nice to do something with this error message.
 }
 
+#if LIBXML_VERSION >= 21200
+void XSLTProcessor::parseErrorFunc(void* userData, const xmlError* error)
+#else
 void XSLTProcessor::parseErrorFunc(void* userData, xmlError* error)
+#endif
 {
     PageConsoleClient* console = static_cast<PageConsoleClient*>(userData);
     if (!console)

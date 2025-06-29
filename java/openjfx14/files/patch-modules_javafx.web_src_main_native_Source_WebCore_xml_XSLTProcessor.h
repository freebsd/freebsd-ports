--- modules/javafx.web/src/main/native/Source/WebCore/xml/XSLTProcessor.h.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/WebCore/xml/XSLTProcessor.h
@@ -62,7 +62,11 @@ class XSLTProcessor : public RefCounted<XSLTProcessor>
 
     void reset();
 
+#if LIBXML_VERSION >= 21200
+    static void parseErrorFunc(void* userData, const xmlError*);
+#else
     static void parseErrorFunc(void* userData, xmlError*);
+#endif
     static void genericErrorFunc(void* userData, const char* msg, ...);
 
     // Only for libXSLT callbacks

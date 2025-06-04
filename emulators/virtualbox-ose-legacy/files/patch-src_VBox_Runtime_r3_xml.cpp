--- src/VBox/Runtime/r3/xml.cpp.orig	2020-07-09 16:57:46 UTC
+++ src/VBox/Runtime/r3/xml.cpp
@@ -1837,12 +1837,20 @@ static void xmlParserBaseGenericError(void *pCtx, cons
     va_end(args);
 }
 
+#if LIBXML_VERSION >= 21206
+static void xmlStructuredErrorFunc(void *userData, const xmlError *error)
+{
+    NOREF(userData);
+    NOREF(error);
+}
+#else
 static void xmlParserBaseStructuredError(void *pCtx, xmlErrorPtr error)
 {
     NOREF(pCtx);
     /* we expect that there is always a trailing NL */
     LogRel(("XML error at '%s' line %d: %s", error->file, error->line, error->message));
 }
+#endif
 
 XmlParserBase::XmlParserBase()
 {
@@ -1851,7 +1859,11 @@ XmlParserBase::XmlParserBase()
         throw std::bad_alloc();
     /* per-thread so it must be here */
     xmlSetGenericErrorFunc(NULL, xmlParserBaseGenericError);
+#if LIBXML_VERSION >= 21206
+    xmlSetStructuredErrorFunc(NULL, xmlStructuredErrorFunc);
+#else
     xmlSetStructuredErrorFunc(NULL, xmlParserBaseStructuredError);
+#endif
 }
 
 XmlParserBase::~XmlParserBase()
@@ -1912,7 +1924,7 @@ void XmlMemParser::read(const void *pvBuf, size_t cbSi
                                                   pcszFilename,
                                                   NULL,       // encoding = auto
                                                   options)))
-        throw XmlError(xmlCtxtGetLastError(m_ctxt));
+        throw XmlError((xmlErrorPtr)xmlCtxtGetLastError(m_ctxt));
 
     doc.refreshInternals();
 }
@@ -2172,7 +2184,7 @@ void XmlFileParser::read(const RTCString &strFilename,
                                               pcszFilename,
                                               NULL,       // encoding = auto
                                               options)))
-        throw XmlError(xmlCtxtGetLastError(m_ctxt));
+        throw XmlError((xmlErrorPtr)xmlCtxtGetLastError(m_ctxt));
 
     doc.refreshInternals();
 }

--- cegui/src/XMLParserModules/Libxml2/XMLParser.cpp.orig	2016-04-23 18:19:40 UTC
+++ cegui/src/XMLParserModules/Libxml2/XMLParser.cpp
@@ -99,7 +99,11 @@ void LibxmlParser::parseXML(XMLHandler& handler,
 
     if (!doc)
     {
+#if LIBXML_VERSION >= 21200
+        const xmlError* err = xmlGetLastError();
+#else
         xmlError* err = xmlGetLastError();
+#endif
 
         CEGUI_THROW(GenericException(
             String("xmlParseMemory failed in file: '") +

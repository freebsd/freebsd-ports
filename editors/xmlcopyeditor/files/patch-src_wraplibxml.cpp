Fix with libxml2-2.14
https://sourceforge.net/p/xml-copy-editor/bugs/242/

--- src/wraplibxml.cpp.orig	2025-05-15 17:09:04 UTC
+++ src/wraplibxml.cpp
@@ -54,7 +54,11 @@ class Initializer (public)
 		xmlLoadCatalog ( CONV ( catalogPath ) );
 		::catalog = xmlLoadACatalog ( CONV ( catalogPath ) );
 
+#if LIBXML_VERSION < 21400
 		initGenericErrorDefaultFunc ( NULL );
+#else
+		xmlSetGenericErrorFunc ( NULL, NULL );
+#endif
 	}
 
 	~Initializer ()
@@ -472,7 +476,7 @@ std::string WrapLibxml::dumpXPathObject ( xmlXPathObje
 	case XPATH_STRING:
 		sstream << obj->stringval;
 		break;
-
+#if LIBXML_VERSION < 21400
 	case XPATH_POINT:
 		xmlBufferPtr bufferPtr;
 		bufferPtr = xmlBufferCreate();
@@ -486,6 +490,7 @@ std::string WrapLibxml::dumpXPathObject ( xmlXPathObje
 
 	case XPATH_RANGE:
 	case XPATH_LOCATIONSET:
+#endif
 	case XPATH_XSLT_TREE:
 	default:
 		FILE *fp = tmpfile();
@@ -706,7 +711,7 @@ wxString WrapLibxml::getLastError()
 
 wxString WrapLibxml::getLastError()
 {
-	xmlErrorPtr err = xmlGetLastError();
+	const xmlError *err = xmlGetLastError();
 
 	if ( !err )
 		return nonParserError;
@@ -722,7 +727,7 @@ std::pair<int, int> WrapLibxml::getErrorPosition()
 
 std::pair<int, int> WrapLibxml::getErrorPosition()
 {
-	xmlErrorPtr err = xmlGetLastError();
+	const xmlError *err = xmlGetLastError();
 	if ( !err )
 		return std::make_pair ( 1, 1 );
 

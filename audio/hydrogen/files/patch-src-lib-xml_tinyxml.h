--- src/lib/xml/tinyxml.h.orig	2007-11-27 00:59:06.000000000 +0100
+++ src/lib/xml/tinyxml.h	2007-11-27 01:05:34.000000000 +0100
@@ -823,7 +823,7 @@
 #endif
 
 	/// Construct.
-	TiXmlDeclaration::TiXmlDeclaration( const char * _version,
+	TiXmlDeclaration( const char * _version,
 										const char * _encoding,
 										const char * _standalone );
 

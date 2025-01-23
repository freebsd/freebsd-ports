Fix with >libxml2-2.12
https://sourceforge.net/p/xml-copy-editor/bugs/239/

--- src/wraplibxml.cpp.orig	2025-01-23 10:31:01 UTC
+++ src/wraplibxml.cpp
@@ -706,7 +706,7 @@ wxString WrapLibxml::getLastError()
 
 wxString WrapLibxml::getLastError()
 {
-	xmlErrorPtr err = xmlGetLastError();
+	const xmlError *err = xmlGetLastError();
 
 	if ( !err )
 		return nonParserError;
@@ -722,7 +722,7 @@ std::pair<int, int> WrapLibxml::getErrorPosition()
 
 std::pair<int, int> WrapLibxml::getErrorPosition()
 {
-	xmlErrorPtr err = xmlGetLastError();
+	const xmlError *err = xmlGetLastError();
 	if ( !err )
 		return std::make_pair ( 1, 1 );
 

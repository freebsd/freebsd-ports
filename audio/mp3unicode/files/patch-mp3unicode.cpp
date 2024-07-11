Fix build with Taglib 2.x

--- mp3unicode.cpp.orig	2012-05-07 12:03:19 UTC
+++ mp3unicode.cpp
@@ -192,7 +192,7 @@ class Converter { (protected)
 	bool
 	heuristicIsUnicode (TagLib::String string) {
 		unsigned u0080 = 0;
-		for(TagLib::uint i = 0; i < string.size(); i++) {
+		for(uint i = 0; i < string.size(); i++) {
 			if(string[i] > 255) {
 				return true;
 			}

--- src/c-int-source-funcs.inc.orig	2014-11-13 13:12:24 UTC
+++ src/c-int-source-funcs.inc
@@ -157,7 +157,7 @@ std::string GetMapValue(std::map<std::st
 		if (o) \
 		{ \
 			try { \
-				((MusicBrainz5::C##TYPE1 *)o)->Set##PROP1(str); \
+				((MusicBrainz5::C##TYPE1 *)o)->Set##PROP1(str ? str : ""); \
 			} \
 			catch (...) { \
 			} \

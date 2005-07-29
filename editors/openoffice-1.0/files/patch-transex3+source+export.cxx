Adding UKRAINIAN language

--- transex3/source/export.cxx.orig	Mon Feb 24 17:45:55 2003
+++ transex3/source/export.cxx	Tue Feb 25 17:14:06 2003
@@ -1205,6 +1205,8 @@
 		return PORTUGUESE_INDEX;
 	else if ( sLang == "RUSSIAN" )
 		return RUSSIAN_INDEX;
+	else if ( sLang == "UKRAINIAN" )
+		return UKRAINIAN_INDEX;
 	else if ( sLang == "GREEK" )
 		return GREEK_INDEX;
 	else if ( sLang == "DUTCH" )

Adding ukrainian language

--- transex3/inc/export.hxx.orig	Fri May 24 15:26:18 2002
+++ transex3/inc/export.hxx	Tue Feb 25 17:13:09 2003
@@ -187,18 +187,22 @@
 #define CATALAN_ISO				"ca"
 #define CATALAN_INDEX				28
 
+#define UKRAINIAN					38
+#define UKRAINIAN_ISO				"uk"
+#define UKRAINIAN_INDEX				29
+
 #define THAI					66
 #define THAI_ISO				"th"
-#define THAI_INDEX					29
+#define THAI_INDEX					30
 
 // special language for l10n framework
 #define EXTERN					99
-#define EXTERN_INDEX				30
+#define EXTERN_INDEX				31
 
-#define LANGUAGES					31
+#define LANGUAGES					32
 
 #define LANGUAGE_ALLOWED( n )  (( n != 0xFFFF ) && ( Export::LanguageAllowed( Export::LangId[ n ] )) && 													\
-							   (( Export::LangId[ n ] == 01 ) || ( Export::LangId[ n ] == 03 ) || ( Export::LangId[ n ] == 07 ) || 	\
+							   (( Export::LangId[ n ] == 01 ) || ( Export::LangId[ n ] == 03 ) || ( Export::LangId[ n ] == 07 ) || ( Export::LangId[ n ] == 38 ) ||	\
 								( Export::LangId[ n ] == 30 ) || ( Export::LangId[ n ] == 31 ) || ( Export::LangId[ n ] == 33 ) ||   	\
 								( Export::LangId[ n ] == 34 ) || ( Export::LangId[ n ] == 35 ) || ( Export::LangId[ n ] == 37 ) || 	\
 								( Export::LangId[ n ] == 39 ) || ( Export::LangId[ n ] == 45 ) || ( Export::LangId[ n ] == 46 ) || 	\

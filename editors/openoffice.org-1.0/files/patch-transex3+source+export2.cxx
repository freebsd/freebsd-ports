adding ukrainian language
--- transex3/source/export2.cxx.orig	Mon Feb 24 17:45:55 2003
+++ transex3/source/export2.cxx	Tue Feb 25 17:19:19 2003
@@ -144,6 +144,7 @@
 	ARABIC,
 	HEBREW,
 	CATALAN,
+	UKRAINIAN,
 	THAI,
 	EXTERN
 };
@@ -192,6 +193,7 @@
 		case ARABIC: return RTL_TEXTENCODING_MS_1256;
 		case HEBREW: return RTL_TEXTENCODING_MS_1255;
 		case CATALAN: return RTL_TEXTENCODING_MS_1252;
+		case UKRAINIAN: return RTL_TEXTENCODING_MS_1251;
 		case THAI: return RTL_TEXTENCODING_UTF8;
 		case EXTERN: return RTL_TEXTENCODING_UTF8;
 	}
@@ -214,6 +216,8 @@
 		return PORTUGUESE;
 	else if ( sLang == ByteString( RUSSIAN_ISO ).ToUpperAscii())
 		return RUSSIAN;
+	else if ( sLang == ByteString( UKRAINIAN_ISO ).ToUpperAscii())
+		return UKRAINIAN;
 	else if ( sLang == ByteString( GREEK_ISO ).ToUpperAscii())
 		return GREEK;
 	else if ( sLang == ByteString( DUTCH_ISO ).ToUpperAscii())
@@ -279,6 +283,7 @@
 		case ENGLISH_US_INDEX: return ENGLISH_US_ISO;
 		case PORTUGUESE_INDEX: return PORTUGUESE_ISO;
 		case RUSSIAN_INDEX: return RUSSIAN_ISO;
+		case UKRAINIAN_INDEX: return UKRAINIAN_ISO;
 		case GREEK_INDEX: return GREEK_ISO;
 		case DUTCH_INDEX: return DUTCH_ISO;
 		case FRENCH_INDEX: return FRENCH_ISO;
@@ -429,6 +434,7 @@
 	"arabic",
 	"hebrew",
 	"catalan",
+	"ukrainian",
 	"thai",
 	"extern"
 };

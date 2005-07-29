--- tools/source/inet/inetmime.cxx.orig	Mon Feb 24 17:46:55 2003
+++ tools/source/inet/inetmime.cxx	Tue Feb 25 17:08:22 2003
@@ -1633,7 +1633,8 @@
 				"ISO-8859-10", // RTL_TEXTENCODING_ISO_8859_10, RFC 2047
 				"ISO-8859-13", // RTL_TEXTENCODING_ISO_8859_13, RFC 2047
 				"EUC-KR", // RTL_TEXTENCODING_EUC_KR
-				"ISO-2022-KR" }; // RTL_TEXTENCODING_ISO_2022_KR
+				"ISO-2022-KR", // RTL_TEXTENCODING_ISO_2022_KR
+				"KOI8-U" }; // RTL_TEXTENCODING_KOI8_U
 		DBG_ASSERT(aMap[eEncoding],
 				   "INetMIME::getCharsetName(): Unsupported encoding");
 		return aMap[eEncoding];
@@ -1841,7 +1842,8 @@
 		{ "ISO-10646-UCS-4", RTL_TEXTENCODING_UCS4 },
 		{ "CSUCS4", RTL_TEXTENCODING_UCS4 },
 		{ "ISO-10646-UCS-2", RTL_TEXTENCODING_UCS2 },
-		{ "CSUNICODE", RTL_TEXTENCODING_UCS2 } };
+		{ "CSUNICODE", RTL_TEXTENCODING_UCS2 },
+		{ "KOI8-U", RTL_TEXTENCODING_KOI8_U } };
 
 //============================================================================
 template< typename T >
@@ -2012,6 +2014,18 @@
 		// <ftp://ftp.unicode.org/Public/MAPPINGS/VENDORS/MISC/KOI8-R.TXT>
 		// version 1.0 of 18 August 1999
 
+	static const sal_uInt32 aKOI8URanges[]
+		= { 0, 0x7F, 0xA0, 0xA0, 0xA9, 0xA9, 0xB0, 0xB0, 0xB2, 0xB2,
+			0xB7, 0xB7, 0xF7, 0xF7, 0x401, 0x401, 0x410, 0x44F, 0x451, 0x451,
+			0x2219, 0x221A, 0x2248, 0x2248, 0x2264, 0x2265, 0x2320, 0x2321,
+			0x2500, 0x2500, 0x2502, 0x2502, 0x250C, 0x250C, 0x2510, 0x2510,
+			0x2514, 0x2514, 0x2518, 0x2518, 0x251C, 0x251C, 0x2524, 0x2524,
+			0x252C, 0x252C, 0x2534, 0x2534, 0x253C, 0x253C, 0x2550, 0x256C,
+			0x2580, 0x2580, 0x2584, 0x2584, 0x2588, 0x2588, 0x258C, 0x258C,
+			0x2590, 0x2593, 0x25A0, 0x25A0, sal_uInt32(-1) };
+		// <ftp://ftp.unicode.org/Public/MAPPINGS/VENDORS/MISC/KOI8-R.TXT>
+		// version 1.0 of 18 August 1999
+
 	static const sal_uInt32 aWindows1252Ranges[]
 		= { 0, 0x7F, 0xA0, 0xFF, 0x152, 0x153, 0x160, 0x161, 0x178, 0x178,
 			0x17D, 0x17E, 0x192, 0x192, 0x2C6, 0x2C6, 0x2DC, 0x2DC,
@@ -2133,6 +2147,12 @@
 			pList->prepend(Charset(RTL_TEXTENCODING_ISO_8859_5,
 								   aISO88595Ranges));
 			pList->prepend(Charset(RTL_TEXTENCODING_KOI8_R, aKOI8RRanges));
+			break;
+
+		case RTL_TEXTENCODING_KOI8_U:
+			pList->prepend(Charset(RTL_TEXTENCODING_ISO_8859_5,
+								   aISO88595Ranges));
+			pList->prepend(Charset(RTL_TEXTENCODING_KOI8_U, aKOI8URanges));
 			break;
 
 		default: //@@@ more cases are missing!

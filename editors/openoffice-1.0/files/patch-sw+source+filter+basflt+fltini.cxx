--- sw/source/filter/basflt/fltini.cxx.orig	Mon Feb 24 17:46:43 2003
+++ sw/source/filter/basflt/fltini.cxx	Tue Feb 25 16:59:03 2003
@@ -1007,7 +1007,8 @@
 		sToken081[] = "JIS_X_212",
 		sToken082[] = "MS_1361",
 		sToken083[] = "GB_18030",
-		sToken084[] = "UNICODE_2"
+		sToken084[] = "KOI8_U",
+		sToken085[] = "UNICODE_2"
 			;
 	struct _Dummy_MAP
 	{
@@ -1099,7 +1100,8 @@
 		RTL_TEXTENCODING_JIS_X_0212,            sToken081,
 		RTL_TEXTENCODING_MS_1361,               sToken082,
 		RTL_TEXTENCODING_GB_18030,              sToken083,
-		RTL_TEXTENCODING_UCS2,              	sToken084
+		RTL_TEXTENCODING_KOI8_U,              	sToken084,
+		RTL_TEXTENCODING_UCS2,              	sToken085
 	};
 
 	BOOL bFnd = FALSE;

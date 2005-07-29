--- vcl/unx/source/gdi/salcvt.cxx.orig	Mon Feb 24 17:46:21 2003
+++ vcl/unx/source/gdi/salcvt.cxx	Tue Feb 25 17:21:50 2003
@@ -261,6 +261,17 @@
 					||	( nChar >= 0x2500 && nChar <= 0x25a0 );
 			break;
 
+		case RTL_TEXTENCODING_KOI8_U:
+			bMatch = 	( nChar >= 0x0020 && nChar <= 0x007e )
+					||	( nChar >= 0x00a0 && nChar <= 0x00b7 )
+					||	( nChar == 0x00f7 )
+					||	( nChar >= 0x0401 && nChar <= 0x0491 )
+					||	( nChar >= 0x2219 && nChar <= 0x221a )
+					||	( nChar >= 0x2248 && nChar <= 0x2265 )
+					||	( nChar >= 0x2320 && nChar <= 0x2321 )
+					||	( nChar >= 0x2500 && nChar <= 0x25a0 );
+			break;
+
 		case RTL_TEXTENCODING_UNICODE:
 			bMatch = True;
 			break;

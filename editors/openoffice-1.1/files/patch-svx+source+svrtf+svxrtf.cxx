--- ../svx/source/svrtf/svxrtf.cxx.orig	2003-01-17 22:27:36.000000000 +0900
+++ ../svx/source/svrtf/svxrtf.cxx	2003-04-06 00:37:52.000000000 +0900
@@ -583,8 +583,14 @@
 
 		case RTF_FCHARSET:
 			if( -1 != nTokenValue )
-				pFont->SetCharSet( rtl_getTextEncodingFromWindowsCharset(
-										(BYTE)nTokenValue ) );
+			{
+//				pFont->SetCharSet( rtl_getTextEncodingFromWindowsCharset(
+//										(BYTE)nTokenValue ) );
+				CharSet nCharSet =
+					rtl_getTextEncodingFromWindowsCharset( (BYTE)nTokenValue );
+				pFont->SetCharSet( nCharSet );
+				SetEncoding( nCharSet );	//Takashi Ono
+			}
 			break;
 
 		case RTF_FPRQ:

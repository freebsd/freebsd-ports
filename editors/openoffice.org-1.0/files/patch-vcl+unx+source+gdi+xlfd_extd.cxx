--- vcl/unx/source/gdi/xlfd_extd.cxx.orig	Mon Feb 24 17:46:21 2003
+++ vcl/unx/source/gdi/xlfd_extd.cxx	Tue Feb 25 17:22:26 2003
@@ -205,6 +205,7 @@
 			case RTL_TEXTENCODING_ISO_8859_15:
 			case RTL_TEXTENCODING_MS_1251:
 			case RTL_TEXTENCODING_KOI8_R:
+			case RTL_TEXTENCODING_KOI8_U:
 			case RTL_TEXTENCODING_JIS_X_0201:
 				if ( nLargestRange < 0x0080 )
 				{

--- sal/inc/rtl/textenc.h.orig	Mon Feb 24 17:46:26 2003
+++ sal/inc/rtl/textenc.h	Tue Feb 25 16:45:00 2003
@@ -173,8 +173,9 @@
 #define RTL_TEXTENCODING_MS_1361                (RTL_TEXTENC_CAST( 84 ))
 #define RTL_TEXTENCODING_GB_18030               (RTL_TEXTENC_CAST( 85 ))
 #define RTL_TEXTENCODING_BIG5_HKSCS             (RTL_TEXTENC_CAST( 86 ))
+#define RTL_TEXTENCODING_KOI8_U                 (RTL_TEXTENC_CAST( 87 ))
 
-#define RTL_TEXTENCODING_STD_COUNT              (RTL_TEXTENC_CAST( 87 ))
+#define RTL_TEXTENCODING_STD_COUNT              (RTL_TEXTENC_CAST( 88 ))
 
 #define RTL_TEXTENCODING_USER_START             (RTL_TEXTENC_CAST( 0x8000 ))
 #define RTL_TEXTENCODING_USER_END               (RTL_TEXTENC_CAST( 0xEFFF ))
@@ -223,6 +224,7 @@
 Cyrillic (DOS/OS2-866/Russian)                  RTL_TEXTENCODING_IBM_866
 Cyrillic (ISO-8859-5)                           RTL_TEXTENCODING_ISO_8859_5
 Cyrillic (KOI8-R)                               RTL_TEXTENCODING_KOI8_R
+Cyrillic (KOI8-U)                               RTL_TEXTENCODING_KOI8_U
 Cyrillic (Windows-1251)                         RTL_TEXTENCODING_MS_1251
 
 Greek (Apple Macintosh)                         RTL_TEXTENCODING_APPLE_GREEK

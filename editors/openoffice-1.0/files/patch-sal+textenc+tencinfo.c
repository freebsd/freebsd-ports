--- sal/textenc/tencinfo.c.orig	Wed Jul 31 11:44:35 2002
+++ sal/textenc/tencinfo.c	Wed Jul 31 11:45:47 2002
@@ -532,6 +532,7 @@
     static ImplStrCharsetDef const aUnixCharsetKOI8Tab[] =
     {
         { "r", RTL_TEXTENCODING_KOI8_R },
+        { "u", RTL_TEXTENCODING_KOI8_U },
         { NULL, RTL_TEXTENCODING_DONTKNOW }
     };
 
@@ -695,6 +695,10 @@
     /* characters. The function search for the first equal string in */
     /* the table. In this table are only the most used mime types. */
     /* Sort order: important */
+
+    if (pMimeCharset == NULL)
+	pMimeCharset = "usascii";
+
     static ImplStrCharsetDef const aVIPMimeCharsetTab[] =
     {
         { "usascii", RTL_TEXTENCODING_ASCII_US },
@@ -741,6 +742,7 @@
         { "windows1256", RTL_TEXTENCODING_MS_1256 },
         { "windows1257", RTL_TEXTENCODING_MS_1257 },
         { "windows1258", RTL_TEXTENCODING_MS_1258 },
+        { "koi8u", RTL_TEXTENCODING_KOI8_U },
         { NULL, RTL_TEXTENCODING_DONTKNOW }
     };
 
@@ -815,6 +817,7 @@
         { "iso10646us", RTL_TEXTENCODING_ASCII_US },
         { "iso646irv", RTL_TEXTENCODING_ASCII_US },
         { "cskoi8r", RTL_TEXTENCODING_KOI8_R },
+        { "cskoi8u", RTL_TEXTENCODING_KOI8_U },
         { "ibm437", RTL_TEXTENCODING_IBM_437 },
         { "cp437", RTL_TEXTENCODING_IBM_437 },
         { "437", RTL_TEXTENCODING_IBM_437 },

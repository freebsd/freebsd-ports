--- ../sal/textenc/tencinfo.c.orig	Fri Apr 11 16:25:01 2003
+++ ../sal/textenc/tencinfo.c	Sat May 31 23:33:43 2003
@@ -668,6 +668,10 @@
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

--- ../sal/textenc/tencinfo.c.orig	Wed Jul 31 11:44:35 2002
+++ ../sal/textenc/tencinfo.c	Wed Jul 31 11:45:47 2002
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

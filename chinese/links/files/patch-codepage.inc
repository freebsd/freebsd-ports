--- codepage.inc.orig	2002-12-26 22:55:22.000000000 +0800
+++ codepage.inc	2002-12-27 01:38:21.000000000 +0800
@@ -4017,6 +4017,9 @@
 
 unsigned char *aliases_utf_8 [] = {"utf-8", "utf8", NULL };
 
+unsigned char *aliases_cjk [] = {"BIG-5", "BIG5", "GB-2312", "GB2312", "JIS", "SJIS", "X-SJIS", "Shift_JIS", "iso-2022-jp", "euc-kr", NULL };
+
+
 struct codepage_desc codepages [] = {
 	{ "7-bit ASCII", aliases_7bit, table_7bit },
 	{ "ISO 8859-1", aliases_8859_1, table_8859_1 },
@@ -4052,5 +4055,7 @@
 	{ "TCVN-5712", aliases_tcvn5712, table_tcvn5712 },
 	{ "VISCII", aliases_viscii, table_viscii },
 	{ "Unicode UTF-8", aliases_utf_8, table_utf_8 },
+	{ "CJK", aliases_cjk, table_8859_1},
+	
 	{ NULL, NULL, NULL }
 };


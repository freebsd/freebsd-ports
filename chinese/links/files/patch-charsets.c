--- charsets.c.orig	2002-12-26 22:54:32.000000000 +0800
+++ charsets.c	2002-12-26 23:24:35.000000000 +0800
@@ -87,7 +87,7 @@
 	int j, s;
 	if (u < 128) return strings[u];
 	if (u == 0xa0) return "\001";
-	if (u == 0xad) return "";
+	if (!is_cjk_cp(to) && u == 0xad) return "";
 	if (codepages[to].table == table_utf_8) return encode_utf_8(u);
 	if (u < 0xa0) {
 		if (!strange_chars[u - 0x80]) return NULL;
@@ -498,3 +498,9 @@
 {
 	return codepages[index].table == table_utf_8;
 }
+	
+int is_cjk_cp(int index)
+{
+       return ! strcmp(codepages[index].name, "CJK");
+	
+}


--- src/fe-text/utf8.c.orig	Tue Oct 15 02:45:08 2002
+++ src/fe-text/utf8.c	Wed Apr  7 11:04:22 2004
@@ -180,6 +180,24 @@
 	*out = '\0';
 }
 
+void utf16_to_utf8_with_pos(const unichar *str, int spos, char *out, int *opos)
+{
+	int len;
+	const unichar *sstart = str;
+	char *ostart = out;
+
+	*opos = 0;
+	while (*str != '\0') {
+		len = utf16_char_to_utf8(*str, out);
+                out += len;
+
+		str++;
+		if(str - sstart == spos)
+			*opos = out - ostart;
+	}
+	*out = '\0';
+}
+
 static const unichar wcc[] = {
 	0x0, 0x300, 0x34F, 0x360, 0x363, 0x483, 0x487, 0x488, 0x48A, 0x591,
 	0x5A2, 0x5A3, 0x5BA, 0x5BB, 0x5BE, 0x5BF, 0x5C0, 0x5C1, 0x5C3, 0x5C4,

--- ./src/japanese_tag.c.orig	Fri Jan  5 00:35:31 2001
+++ ./src/japanese_tag.c	Fri Jan  4 05:58:49 2002
@@ -64,6 +64,16 @@
 	*p2 -= cellOffset;
 }
 
+static void _sjis_rev_shift(int *p1, int *p2)
+{
+	unsigned char c1 = *p1;
+	unsigned char c2 = *p2;
+	int rowOffset = c1 < 95 ? 112 : 176;
+	int cellOffset = c1 % 2 ? (c2 > 95 ? 32 : 31) : 126;
+	*p1 = ((c1 + 1) >> 1) + rowOffset;
+	*p2 += cellOffset;
+}
+
 static unsigned char *_skip_esc(unsigned char *str, int *esc_in)
 {
 	int c;
@@ -139,6 +149,36 @@
 	*str2 = '\0';
 }
 
+static void _euc2shift(unsigned char const *str, unsigned char *str2)
+{
+	int p1,p2;
+  
+	while ((p1 = (int)*str) != '\0') {
+                /* SB-SJIS with SS2 */
+		if (p1 == 0x8e) {
+			if((p2 = (int)*(++str)) == '\0') break;
+			CHAROUT(p1);
+			str++;
+			continue;
+		}
+
+		if ( (p1 >= 161) && ( p1 <= 254) ) {
+			if ((p2 = (int)*(++str)) == '\0') break;
+			if ( (p2 >= 161) && ( p2 <= 254) ) {
+				p1 -= 128, p2 -= 128;
+				_sjis_rev_shift(&p1,&p2);
+			}
+			CHAROUT(p1);
+			CHAROUT(p2);
+			str++;
+			continue;
+		}
+		CHAROUT(p1);
+		str++;
+	}
+	*str2='\0';
+}
+
 static int _detect(unsigned char *str, int expected)
 {
 	register int c;
@@ -313,6 +353,22 @@
 
 	ret = g_strdup(buf);
 	g_free(buf);
+	return ret;
+}
+
+char *to_string_sjis_from_euc(char const *str)
+{
+	char *buf, *ret;
+
+	if(!str) return (NULL);
+
+	buf = (char*)g_malloc(strlen(str)*2 + 1);
+	if (!buf) return NULL;
+
+	_euc2shift((unsigned char *)str, (unsigned char *)buf);
+
+	ret = strdup(buf);
+	free(buf);
 	return ret;
 }
 

--- src/mpg_tagutil.c.orig	Sun Aug 18 12:29:35 2002
+++ src/mpg_tagutil.c	Sun Dec 26 01:58:21 2004
@@ -162,6 +162,12 @@
 	FILE *f;
 	gchar buf[130];
 	gint i;
+#ifdef ENABLE_JAPANESE_TAGS
+	gchar tmpbuf[31];
+	gchar *ctp;
+
+	tmpbuf[30] = '\0';
+#endif
 
 	f = fopen(path,"r+");
         if (!f)
@@ -222,6 +228,86 @@
 		}
 
 	strncpy(buf, "TAG", 3);
+#ifdef ENABLE_JAPANESE_TAGS
+	if (title && *title) {
+		strncpy(tmpbuf, title, 30);
+		ctp = to_string_sjis_from_euc(tmpbuf);
+		if (ctp) {
+			strncpy(buf + 3, ctp, 30);
+			free(ctp);
+		}
+		else {
+			printf("fail to convert title tag encoding\n");
+			fclose(f);
+			return FALSE;
+		}
+	}
+	if (artist && *artist) {
+		strncpy(tmpbuf, artist, 30);
+		ctp = to_string_sjis_from_euc(tmpbuf);
+		if (ctp) {
+			strncpy(buf + 33, ctp, 30);
+			free(ctp);
+		}
+		else {
+			printf("fail to convert artist tag encoding\n");
+			fclose(f);
+			return FALSE;
+		}
+	}
+	if (album && *album) {
+		strncpy(tmpbuf, album, 30);
+		ctp = to_string_sjis_from_euc(tmpbuf);
+		if (ctp) {
+			strncpy(buf + 63, ctp, 30);
+			free(ctp);
+		}
+		else {
+			printf("fail to convert album tag encoding\n");
+			fclose(f);
+			return FALSE;
+		}
+	}
+	if (year) strncpy(buf + 93, year, 4);
+	if (comment && track == 0 && strlen(ctp) > 28)
+		{
+		/* comment is longer than 28 and no track number,
+		 * write a v1.0 tag to enable larger comments
+		 */
+		strncpy(tmpbuf, comment, 30);
+		ctp = to_string_sjis_from_euc(tmpbuf);
+		if (ctp)
+			{
+			strncpy(buf + 97, ctp, 30);
+			free(ctp);
+			}
+		else
+			{
+			printf("fail to convert comment tag encoding\n");
+			fclose(f);
+			return FALSE;
+			}
+
+		}
+	else
+		{
+		buf[126] = track;
+
+		strncpy(tmpbuf, comment, 30);
+		ctp = to_string_sjis_from_euc(tmpbuf);
+		if (ctp)
+			{
+			strncpy(buf + 97, ctp, 28);
+			free(ctp);
+			}
+		else
+			{
+			printf("fail to convert comment tag encoding\n");
+			fclose(f);
+			return FALSE;
+			}
+		}
+#else
 	if (title) strncpy(buf + 3, title, 30);
 	if (artist) strncpy(buf + 33, artist, 30);
 	if (album) strncpy(buf + 63, album, 30);
@@ -239,6 +325,7 @@
 		if (comment) strncpy(buf + 97, comment, 28);
 		buf[126] = track;
 		}
+#endif
 
 	buf[127] = genre;

--- ./src/mpg_tagutil.c.orig	Thu Oct 25 10:56:57 2001
+++ ./src/mpg_tagutil.c	Fri Jan  4 05:58:35 2002
@@ -149,6 +149,12 @@
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
@@ -209,11 +215,67 @@
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
+        	        printf("fail to convert title tag encoding\n");
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
+        	        printf("fail to convert artist tag encoding\n");
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
+        	        printf("fail to convert album tag encoding\n");
+			fclose(f);
+			return FALSE;
+		}
+	}
+	if (year) strncpy(buf + 93, year, 4);
+	if (comment && *comment) {
+		strncpy(tmpbuf, comment, 30);
+		ctp = to_string_sjis_from_euc(tmpbuf);
+		if (ctp) {
+			strncpy(buf + 97, ctp, 30);
+			free(ctp);
+		}
+		else {
+        	        printf("fail to convert comment tag encoding\n");
+			fclose(f);
+			return FALSE;
+		}
+	}
+#else
 	if (title) strncpy(buf + 3, title, 30);
 	if (artist) strncpy(buf + 33, artist, 30);
 	if (album) strncpy(buf + 63, album, 30);
 	if (year) strncpy(buf + 93, year, 4);
 	if (comment) strncpy(buf + 97, comment, 30);
+#endif
 
 	for (i=0; i<128; i++)
 		{

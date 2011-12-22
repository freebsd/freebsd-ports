--- ./misc.c.orig	1991-07-16 17:52:54.000000000 +0200
+++ ./misc.c	2011-12-22 14:02:23.000000000 +0100
@@ -135,11 +135,16 @@
 char *fullpath (direntry)
 struct direntry *direntry;
 {
-	static char result[PATHSIZE];
+	static char result[PATHSIZE+PATHSIZE+12]; /* Room for enough space */
 	combine (result,
 				direntry->dirlen != 0 ? direntry->dirname : "", 
 				(direntry->namlen != 0) ? direntry->lfname : direntry->fname
 			  );
+
+	if (strlen (result) >= PATHSIZE) {
+		prterror ('f', "Combined dirname and filename too long\n");
+	}
+
 	return (result);
 }
 
@@ -172,7 +177,11 @@
 
    frd_zooh (header, zoo_file);
 
+#ifdef __LP64__
+   if ((int)(header->zoo_start + header->zoo_minus) != 0)
+#else
    if ((header->zoo_start + header->zoo_minus) != 0L)
+#endif
       prterror ('f', failed_consistency);
    if (ver_too_high (header))
       prterror ('f', wrong_version, header->major_ver, header->minor_ver);

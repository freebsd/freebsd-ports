--- misc.c.orig	Tue Jul 16 17:52:54 1991
+++ misc.c	Thu Apr  6 08:45:41 2006
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
 

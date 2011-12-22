--- Complete.c.orig	1996-10-18 13:10:31.000000000 +0800
+++ Complete.c	2011-12-22 00:11:03.000000000 +0800
@@ -241,7 +241,11 @@ FileListAdd(FileList *f, char *s)
 static int
 CompareStrings(char **a, char **b)
 {
+#ifdef __FreeBSD__
+	return strcoll(*a, *b);
+#else
 	return strcmp(*a, *b);
+#endif
 }
 
 static void

--- osdep/strltest.c.orig	Fri Jan 24 00:04:54 2003
+++ osdep/strltest.c	Fri Jan 24 00:07:05 2003
@@ -5,7 +5,7 @@
 int
 main(void)
 {
-	char a[2];
-	strlcpy(a, "666", sizeof(a));
+	char a[10];
+	strlncat(a, "666", 3);
 	return 0;
 }

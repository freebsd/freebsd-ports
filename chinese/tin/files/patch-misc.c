--- src/misc.c~	Thu Aug  3 21:49:22 2000
+++ src/misc.c	Wed Nov 29 08:03:36 2000
@@ -1169,6 +1169,7 @@
 my_isprint (
 	int c)
 {
+	return 1;
 #ifndef NO_LOCALE
 	/* use locale */
 	return isprint(c);

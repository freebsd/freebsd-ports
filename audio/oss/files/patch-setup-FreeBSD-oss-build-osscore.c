--- setup/FreeBSD/oss/build/osscore.c.orig	2011-01-04 20:33:08.000000000 -0500
+++ setup/FreeBSD/oss/build/osscore.c	2011-06-21 17:55:55.000000000 -0400
@@ -75,7 +75,7 @@ cmn_err (int level, char *s, ...)
   sprintf (tmp + strlen (tmp), s, a[0], a[1], a[2], a[3], a[4], a[5], NULL,
 	   NULL, NULL, NULL);
   if (level == CE_PANIC)
-    panic (tmp);
+    panic ("%s", tmp);
   printf ("%s", tmp);
 #if 0
   /* This may cause a crash under SMP */

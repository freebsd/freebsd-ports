--- gthumb/glib-utils.c.orig	2011-11-03 21:36:36.000000000 +0100
+++ gthumb/glib-utils.c	2011-12-29 15:30:12.000000000 +0100
@@ -552,7 +552,7 @@
 {
 	int offset;
 
-	offset = -timezone;
+	offset = 0;
 #if defined (HAVE_TM_GMTOFF)
 	offset = tm->tm_gmtoff;
 #elif defined (HAVE_TIMEZONE)

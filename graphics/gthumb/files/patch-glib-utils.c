--- gthumb/glib-utils.c.orig	2011-11-03 21:36:36.000000000 +0100
+++ gthumb/glib-utils.c	2012-05-10 15:03:34.000000000 +0200
@@ -552,7 +552,6 @@
 {
 	int offset;
 
-	offset = -timezone;
 #if defined (HAVE_TM_GMTOFF)
 	offset = tm->tm_gmtoff;
 #elif defined (HAVE_TIMEZONE)
@@ -564,6 +563,8 @@
   #endif
 	} else
 		offset = -timezone;
+#else
+	offset = 0;
 #endif
 
 	return offset;

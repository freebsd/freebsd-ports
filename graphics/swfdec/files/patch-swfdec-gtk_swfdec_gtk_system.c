--- swfdec-gtk/swfdec_gtk_system.c.orig	2008-02-22 15:38:09.000000000 -0500
+++ swfdec-gtk/swfdec_gtk_system.c	2008-02-22 15:38:13.000000000 -0500
@@ -114,8 +114,12 @@ swfdec_gtk_system_get_language (void)
 static int
 swfdec_gtk_system_get_utc_offset (void)
 {
+  struct tm *t;
+  time_t tt;
   tzset ();
-  return timezone / 60;
+  tt = time (NULL);
+  t = localtime (&tt);
+  return t->tm_gmtoff / 60;
 }
 
 /*** PUBLIC API ***/

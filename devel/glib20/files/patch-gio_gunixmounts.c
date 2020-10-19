--- gio/gunixmounts.c.orig	2020-10-01 09:17:53.138733000 -0400
+++ gio/gunixmounts.c	2020-10-15 13:05:40.628175000 -0400
@@ -1389,6 +1389,8 @@
 
 #elif (defined(HAVE_GETVFSSTAT) || defined(HAVE_GETFSSTAT)) && defined(HAVE_FSTAB_H) && defined(HAVE_SYS_MOUNT_H)
 
+G_LOCK_DEFINE_STATIC(getfsent);
+
 static GList *
 _g_get_unix_mount_points (void)
 {
@@ -1400,9 +1402,6 @@
   struct stat sb;
 #endif
   
-  if (!setfsent ())
-    return NULL;
-
   return_list = NULL;
   
 #ifdef HAVE_SYS_SYSCTL_H
@@ -1433,6 +1432,11 @@
 #endif
 #endif
   
+  G_LOCK (getfsent);
+  if (!setfsent ()) {
+    G_UNLOCK (getfsent);
+    return NULL;
+  }
   while ((fstab = getfsent ()) != NULL)
     {
       gboolean is_read_only = FALSE;
@@ -1468,6 +1472,7 @@
     }
   
   endfsent ();
+  G_UNLOCK (getfsent);
   
   return g_list_reverse (return_list);
 }

--- plib/support.c.orig	Thu May  2 05:01:54 2002
+++ plib/support.c	Sat May 18 02:11:58 2002
@@ -369,11 +369,13 @@
     return code;
     
 #else
+    pthread_once_t grp_once;
+    pthread_mutex_t grp_lock;
     struct group *gp;
     int i, len;
 
     
-    pthread_once(&grp_once, grp_lock_init);
+    pthread_once(&grp_once, NULL);
     pthread_mutex_lock(&grp_lock);
 
     gp = getgrgid(gid);

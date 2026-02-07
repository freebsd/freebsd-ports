--- plib/support.c.orig	Thu Jan  9 22:25:01 2003
+++ plib/support.c	Wed Apr  6 00:38:41 2005
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
@@ -452,11 +454,13 @@
     return code;
     
 #else
+    pthread_once_t grp_once;
+    pthread_mutex_t grp_lock;
     struct group *gp;
     int i, len;
 
     
-    pthread_once(&grp_once, grp_lock_init);
+    pthread_once(&grp_once, NULL);
     pthread_mutex_lock(&grp_lock);
 
     gp = getgrnam(name);

--- plib/support.c.orig	Thu Jan  9 14:25:01 2003
+++ plib/support.c	Mon May 23 20:46:01 2005
@@ -145,6 +145,15 @@
     pthread_mutex_init(&pwd_lock, NULL);
 }
 
+static pthread_mutex_t grp_lock;
+static pthread_once_t grp_once = PTHREAD_ONCE_INIT;
+
+static void
+grp_lock_init(void)
+{
+    pthread_mutex_init(&grp_lock, NULL);
+}
+
 static char *
 strcopy(const char *str, char **buf, size_t *avail)
 {

--- record.c.orig	Fri Apr  6 18:36:55 2001
+++ record.c	Fri Apr  6 18:37:03 2001
@@ -20,7 +20,7 @@
 extern void conv_time();
 
 #ifdef SECURE_RECORDFILE
-#define PERM 0644
+#define PERM 0664
 #else
 #define PERM 0666
 #endif

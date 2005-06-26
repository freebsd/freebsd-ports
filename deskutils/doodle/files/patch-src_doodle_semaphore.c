--- src/doodle/semaphore.c.orig	Sun Jun 26 15:20:32 2005
+++ src/doodle/semaphore.c	Sun Jun 26 15:20:45 2005
@@ -36,7 +36,6 @@
 #include <semaphore.h>
 #endif
 #if SOMEBSD
-# include <pthread_np.h>
 #endif
 #if SOMEBSD || OSX
 # include <sys/file.h>

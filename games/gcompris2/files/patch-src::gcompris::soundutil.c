--- src/gcompris/soundutil.c.orig	Sun Dec  7 07:12:51 2003
+++ src/gcompris/soundutil.c	Mon Feb  2 21:44:57 2004
@@ -22,6 +22,7 @@
 #endif
 #include <dirent.h>
 
+#include <signal.h>
 #include "gcompris.h"
 #include <signal.h>
 #include <pthread.h>
@@ -176,6 +177,7 @@
 	{
 	  int err;
 
+	  pthread_mutex_lock( &lock );
 	  err = pthread_cond_wait (&cond, &lock);
 	  if (err)
 	    printf ("cond_wait  : %s\n", strerror (err));

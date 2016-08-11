--- src/main.c.orig	2005-04-15 14:37:41 UTC
+++ src/main.c
@@ -109,6 +109,9 @@
 #include <fcntl.h>
 #include <sys/types.h>
 
+#include <sys/types.h>
+#include <unistd.h>
+
 #ifdef DEMO
 #define DEMO_MSG "\n\nThis is the demo version of the GNUitar program." \
     "\nYou may download the full version as a source distribution" \
@@ -953,9 +956,6 @@ main(int argc, char **argv)
     struct sched_param p;
 
 
-    if ((error = init_sound()) != ERR_NOERROR)
-	return error;
-
     max_priority = sched_get_priority_max(SCHED_FIFO);
     p.sched_priority = max_priority;
 
@@ -964,6 +964,12 @@ main(int argc, char **argv)
 	    ("\nFailed to set scheduler priority. (Are you running as root?)");
 	printf("\nContinuing with default priority");
     }
+
+    setuid(getuid());       /* drop root privileges */
+
+    if ((error = init_sound()) != ERR_NOERROR)
+	return error;
+
     if (pthread_create(&audio_thread, NULL, audio_thread_start, NULL)) {
 	fprintf(stderr, "\nAudio thread creation failed!");
 	return ERR_THREAD;

--- mono/metadata/threads.c.orig	Thu Dec 26 13:00:05 2002
+++ mono/metadata/threads.c	Thu Dec 26 13:00:28 2002
@@ -1099,9 +1099,9 @@
 	/* fixme: store the state somewhere */
 #ifndef __MINGW32__
 #ifdef PTHREAD_POINTER_ID
-	pthread_kill (GUINT_TO_POINTER(thread->tid), SIGRTMIN);
+	pthread_kill (GUINT_TO_POINTER(thread->tid), SIGUSR1);
 #else
-	pthread_kill (thread->tid, SIGRTMIN);
+	pthread_kill (thread->tid, SIGUSR1);
 #endif
 #else
 	g_assert_not_reached ();

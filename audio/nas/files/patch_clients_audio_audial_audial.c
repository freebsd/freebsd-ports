--- clients/audio/audial/audial.c.orig	Wed Nov  5 18:50:21 1997
+++ clients/audio/audial/audial.c	Wed Nov  5 18:56:33 1997
@@ -133,6 +133,7 @@
     signal(SIGALRM, SIG_DFL);
 }
 
+#if !defined(__FreeBSD__) || (__FreeBSD__ < 3)
 static void
 usleep(usecs)
 unsigned int    usecs;
@@ -149,7 +150,7 @@
     setitimer(ITIMER_REAL, &ntval, &otval);
     pause();
 }
-
+#endif
 #endif						/* SYSV else not */
 #endif						/* VMS else not */
 #endif						/* NEEDUSLEEP */

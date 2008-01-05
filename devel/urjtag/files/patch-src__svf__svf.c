--- src/svf/svf.c.orig	Sun Dec 23 15:10:23 2007
+++ src/svf/svf.c	Sat Jan  5 00:46:34 2008
@@ -690,7 +690,11 @@
     unsigned max_time;
 
     sa.sa_handler = sigalrm_handler;
+#ifdef __FreeBSD__
+    sa.sa_flags = SA_RESETHAND;
+#else
     sa.sa_flags = SA_ONESHOT;
+#endif
     sigemptyset(&sa.sa_mask);
     if (sigaction(SIGALRM, &sa, NULL) != 0) {
       perror("sigaction");

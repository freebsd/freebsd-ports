--- frontend/saned.c.orig	2009-03-15 02:35:54.000000000 +0900
+++ frontend/saned.c	2009-05-13 15:18:09.000000000 +0900
@@ -2338,7 +2338,7 @@
 
 #ifdef WITH_AVAHI
 static void
-saned_avahi (void);
+saned_avahi (struct pollfd *fds, int nfds);
 
 static void
 saned_create_avahi_services (AvahiClient *c);
@@ -2351,8 +2351,9 @@
 
 
 static void
-saned_avahi (void)
+saned_avahi (struct pollfd *fds, int nfds)
 {
+  struct pollfd *fdp = NULL;
   int error;
 
   avahi_pid = fork ();
@@ -2371,6 +2372,12 @@
   signal (SIGINT, NULL);
   signal (SIGTERM, NULL);
 
+  /* Close network fds */
+  for (fdp = fds; nfds > 0; nfds--, fdp++)
+    close (fdp->fd);
+
+  free(fds);
+
   avahi_svc_name = avahi_strdup(SANED_NAME);
 
   avahi_poll = avahi_simple_poll_new ();
@@ -3055,7 +3062,7 @@
 
 #ifdef WITH_AVAHI
   DBG (DBG_INFO, "run_standalone: spawning Avahi process\n");
-  saned_avahi ();
+  saned_avahi (fds, nfds);
 #endif /* WITH_AVAHI */
 
   DBG (DBG_MSG, "run_standalone: waiting for control connection\n");

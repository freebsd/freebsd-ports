--- ioloop.c.orig	Tue Dec 14 13:39:31 2004
+++ ioloop.c	Mon May 16 19:24:20 2005
@@ -113,9 +113,9 @@
 
 void fd_event_reset(fd_event *event)
 {
-    event->signalled = 0;
     char buf[1] = {0};
     int flags;
+    event->signalled = 0;
 
     /* set non-blocking on read pipe */
     flags = fcntl(event->pipe[0], F_GETFL, 0);

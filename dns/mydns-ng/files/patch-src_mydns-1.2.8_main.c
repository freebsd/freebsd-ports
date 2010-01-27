--- src/mydns/main.c.orig	2010-01-26 05:17:05.000000000 +0800
+++ src/mydns/main.c	2010-01-26 05:22:38.000000000 +0800
@@ -513,11 +513,11 @@
   /* Close any TCP connections and any NOTIFY sockets */
   for (t = TaskP->head; t; t = TaskP->head) {
     if (t->protocol == SOCK_STREAM && t->fd >= 0)
-      sockclose(t->fd);
+      close(t->fd);
     else if (t->protocol == SOCK_DGRAM
 	     && (t->status & (ReqTask|TickTask|RunTask))
 	     && t->fd >= 0)
-      sockclose(t->fd);
+      close(t->fd);
     dequeue(t);
   }
 }
@@ -747,7 +747,7 @@
 	if (shutting_down) server->pid = -1;
 	else {
 	  if (server->listener) dequeue(server->listener);
-	  sockclose(server->serverfd);
+	  close(server->serverfd);
 	  RELEASE(server);
 	  array_store(Servers, n, NULL);
 	  if (n == 0) server = spawn_server(primary_initial_tasks);
@@ -1164,7 +1164,7 @@
 
 #if HAVE_POLL
 #if DEBUG_ENABLED
-      DebugX("enabled", 1, _("Selecting for IO numfds = %d, timeout = %s(%d)"), numfds,
+      DebugX("enabled", 1, _("Polling for IO numfds = %d, timeout = %s(%d)"), numfds,
 	     (timeoutWanted<0)?"no"
 	     :(timeoutWanted==0)?"poll":"yes", timeoutWanted);
 #endif
@@ -1175,6 +1175,10 @@
       if (errno == EAGAIN) { /* Could fail here but will log and retry */
 	Warn(_("server_loop() received EAGAIN - retrying"));
 	continue;
+      } else {
+#if DEBUG_ENABLED
+	DebugX("enabled", 1, _("poll(): error %d: %s"), errno, strerror(errno));
+#endif
       }
       RELEASE(items);
       if (errno == EINVAL) {
@@ -1213,6 +1217,9 @@
 
       if (rv < 0) {
 	if (errno == EINTR) continue;
+#if DEBUG_ENABLED
+	DebugX("enabled", 1, _("select(): error %d: %s"), errno, strerror(errno));
+#endif
 	if (errno == EBADF) {
 	  /* As we do not get told which FD failed here then purge and try again */
 	  purge_bad_tasks();
@@ -1408,6 +1415,9 @@
 	Warn(_("server_loop() received EAGAIN - retrying"));
 	continue;
       }
+#if DEBUG_ENABLED
+      DebugX("enabled", 1, _("server_loop(): poll() errro %d: %s"), errno, strerror(errno));
+#endif
       RELEASE(items);
       if (errno == EINVAL) {
 	Err(_("server_loop() received EINVAL consistency failure in call to poll/select"));
@@ -1445,6 +1455,9 @@
 
       if (rv < 0) {
 	if (errno == EINTR) continue;
+#if DEBUG_ENABLED
+	DebugX("enabled", 1, _("server_loop(): select() errro %d: %s"), errno, strerror(errno));
+#endif
 	if (errno == EBADF) {
 	  /* As we do not get told which FD failed here then purge and try again */
 	  purge_bad_tasks();
@@ -1466,9 +1479,6 @@
 	if (FD_ISSET(fd, &efd)) {
 	  item->revents |= POLLERR;
 	}
-#if DEBUG_ENABLED
-	DebugX("enabled", 1, _("Item fd = %d, events = %x, revents = %x"), fd, item->events, item->revents);
-#endif
       }
     }
 
@@ -1476,6 +1486,14 @@
 #error You must have either poll (preferred) or select to compile this code
 #endif
 #endif
+#if DEBUG_ENABLED
+    /* Debug socket states */
+    for (i = 0; i < numfds; i++) {
+      struct pollfd *item = &items[i];
+      int fd = item->fd;
+      DebugX("enabled", 1, _("Item fd = %d, events = %x, revents = %x"), fd, item->events, item->revents);
+    }
+#endif
     gettick();
 
     if (shutting_down) { break; }

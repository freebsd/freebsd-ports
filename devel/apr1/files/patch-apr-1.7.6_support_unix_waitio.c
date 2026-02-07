--- apr-1.7.6/support/unix/waitio.c	(revision 1921905)
+++ apr-1.7.6/support/unix/waitio.c	(working copy)
@@ -46,7 +46,10 @@ apr_status_t apr_wait_for_io_or_timeout(apr_file_t
     pfd.fd     = f        ? f->filedes        : s->socketdes;
     pfd.events = for_read ? POLLIN            : POLLOUT;
 
-    if (timeout > 0) {
+    if (timeout < 0) {
+        timeout = -1;
+    }
+    else if (timeout > 0) {
         timeout = (timeout + 999) / 1000;
     }
     do {

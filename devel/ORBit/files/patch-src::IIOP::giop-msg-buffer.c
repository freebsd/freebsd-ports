
$FreeBSD$

--- src/IIOP/giop-msg-buffer.c	2001/10/26 12:42:42	1.1
+++ src/IIOP/giop-msg-buffer.c	2001/10/26 12:42:53
@@ -197,7 +197,17 @@
 	    sum);
   }
 #endif
-  res = writev(fd, curvec, nvecs);
+  for(sum = 0, t = 0; t < nvecs; t++) {
+    do {
+      res = write(fd, curvec[t].iov_base, curvec[t].iov_len);
+    } while (res < 0 && errno == EAGAIN);
+    if (res < 0) {
+      break;
+    } else
+      sum += res;
+  }
+  if (res >= 0)
+    res = sum;
 
   sum = (GIOP_MESSAGE_BUFFER(send_buffer)->message_header.message_size + sizeof(GIOPMessageHeader));
   if(res < sum) {

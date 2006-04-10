--- ddd/TTYAgent.C.orig	Sat Nov  6 19:05:52 2004
+++ ddd/TTYAgent.C	Sat Nov  6 19:08:23 2004
@@ -715,8 +715,19 @@
     }
     else
     {
+#if !defined(__FreeBSD__)
 	if (fcntl(master, F_SETFL, flags | O_NONBLOCK) == -1)
 	    _raiseIOWarning("cannot set file to non-blocking mode");
+#else
+    do {
+        if(fcntl(master, F_SETFL, flags | O_NONBLOCK) != -1)
+            break;
+        else if(errno == EAGAIN)
+            sleep(1);
+        else
+            _raiseIOWarning("cannot set file to non-blocking mode");
+    } while(errno == EAGAIN);
+#endif
     }
 #endif
 	

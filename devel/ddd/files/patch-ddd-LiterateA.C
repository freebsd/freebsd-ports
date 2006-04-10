--- ddd/LiterateA.C.orig	Sat Nov  6 19:00:37 2004
+++ ddd/LiterateA.C	Sat Nov  6 19:04:44 2004
@@ -216,8 +216,12 @@
     int flags = fcntl(fileno(fp), F_GETFL, 0);
     if (flags == -1)
 	_raiseIOWarning("cannot get file descriptor status flags");
-    if (fcntl(fileno(fp), F_SETFL, flags | O_NONBLOCK) == -1)
-	_raiseIOWarning("cannot set file to non-blocking mode");
+    if (fcntl(fileno(fp), F_SETFL, flags | O_NONBLOCK) == -1) {
+#if defined(__FreeBSD__)
+        if(errno != EAGAIN)
+#endif
+        _raiseIOWarning("cannot set file to non-blocking mode");
+    }
 #endif
 
     // Read stuff
@@ -251,8 +255,12 @@
 
 #if HAVE_FCNTL && defined(F_SETFL)
     // Reset file state
-    if (fcntl(fileno(fp), F_SETFL, flags) == -1)
-	_raiseIOWarning("cannot restore file mode");
+    if (fcntl(fileno(fp), F_SETFL, flags) == -1) {
+#if defined(__FreeBSD__)
+        if(errno != EAGAIN)
+#endif
+        _raiseIOWarning("cannot restore file mode");
+    }
 #endif
 
     return nitems;

--- ddd/LiterateA.C.orig	Thu Aug 19 20:16:55 2004
+++ ddd/LiterateA.C	Thu Aug 19 20:23:49 2004
@@ -216,8 +216,12 @@
     int flags = fcntl(fileno(fp), F_GETFL, 0);
     if (flags == -1)
 	_raiseIOWarning("cannot get file descriptor status flags");
-    if (fcntl(fileno(fp), F_SETFL, flags | O_NONBLOCK) == -1)
-	_raiseIOWarning("cannot set file to non-blocking mode");
+    if (fcntl(fileno(fp), F_SETFL, flags | O_NONBLOCK) == -1) {
+#if defined(__FreeBSD__)
+    if(errno != EAGAIN)
+#endif
+	    _raiseIOWarning("cannot set file to non-blocking mode");
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
+    if(errno != EAGAIN)
+#endif
+	    _raiseIOWarning("cannot restore file mode");
+    }
 #endif
 
     return nitems;

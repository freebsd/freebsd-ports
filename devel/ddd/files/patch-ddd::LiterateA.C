--- ddd/LiterateA.C.orig	Sat May 24 11:27:03 2003
+++ ddd/LiterateA.C	Fri Feb 27 13:33:02 2004
@@ -220,8 +220,12 @@
     int flags = fcntl(fileno(fp), F_GETFL, 0);
     if (flags == -1)
 	_raiseIOWarning("cannot get file descriptor status flags");
-    if (fcntl(fileno(fp), F_SETFL, flags | O_NONBLOCK) == -1)
-	_raiseIOWarning("cannot set file to non-blocking mode");
+    if (fcntl(fileno(fp), F_SETFL, flags | O_NONBLOCK) == -1) {
+#if defined(__FreeBSD__)
+	if(errno != EAGAIN)
+#endif
+	    _raiseIOWarning("cannot set file to non-blocking mode");
+    }
 #endif
 
     // Read stuff
@@ -255,8 +259,12 @@
 
 #if HAVE_FCNTL && defined(F_SETFL)
     // Reset file state
-    if (fcntl(fileno(fp), F_SETFL, flags) == -1)
-	_raiseIOWarning("cannot restore file mode");
+    if (fcntl(fileno(fp), F_SETFL, flags) == -1) {
+#if defined(__FreeBSD__)
+	if(errno != EAGAIN)
+#endif
+	    _raiseIOWarning("cannot restore file mode");
+    }
 #endif
 
     return nitems;

--- ddd/TTYAgent.C.orig	2009-02-11 12:25:07.000000000 -0500
+++ ddd/TTYAgent.C	2009-08-22 23:43:03.712807083 -0400
@@ -280,7 +280,9 @@
 #if !defined(__osf__) && \
     HAVE_PTSNAME && HAVE_GRANTPT && HAVE_UNLOCKPT && HAVE_IOCTL
 #define HAVE_UNIX98PTYS 1
+#if !defined(__FreeBSD__)
 #define HAVE_STREAMS_IMPLEMENTATION 1
+#endif
 // FIXME: We should have a proper test for this.
 // For instance, GNU libc 2.1 on Linux (and probably HURD too) has UNIX98-style
 // pty allocation functions, but does not have a STREAMS-based implementation.
@@ -715,8 +717,19 @@
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
 	

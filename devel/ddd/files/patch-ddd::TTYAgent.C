--- ddd/TTYAgent.C.orig	Sat May 24 11:27:05 2003
+++ ddd/TTYAgent.C	Fri Feb 27 13:33:02 2004
@@ -719,8 +719,19 @@
     }
     else
     {
+#if !defined(__FreeBSD__)
 	if (fcntl(master, F_SETFL, flags | O_NONBLOCK) == -1)
 	    _raiseIOWarning("cannot set file to non-blocking mode");
+#else
+	do {
+	    if(fcntl(master, F_SETFL, flags | O_NONBLOCK) != -1)
+		break;
+            else if(errno == EAGAIN)
+		sleep(1);
+	    else 
+	        _raiseIOWarning("cannot set file to non-blocking mode");
+	} while(errno == EAGAIN);
+#endif
     }
 #endif
 	

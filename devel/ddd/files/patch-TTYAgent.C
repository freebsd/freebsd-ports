--- ddd/TTYAgent.C.orig	Thu Aug 19 04:27:58 1999
+++ ddd/TTYAgent.C	Sun Aug 27 02:37:48 2000
@@ -697,8 +697,19 @@
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
 	

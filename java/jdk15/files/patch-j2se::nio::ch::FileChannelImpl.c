$FreeBSD$

--- ../../j2se/src/solaris/native/sun/nio/ch/FileChannelImpl.c.orig	Fri Jul  7 10:47:18 2006
+++ ../../j2se/src/solaris/native/sun/nio/ch/FileChannelImpl.c	Fri Jul  7 14:48:06 2006
@@ -273,14 +273,28 @@
     free(buf);
 
     /*
-     * XXXBSD: there're potential problems with NBIO fd's.  Check it.
+     * Similar to solaris if we've transferred any data return
+     * the number of bytes and ignore any error
+    */
+    if (offset - (off_t)position > 0)
+	return (offset - (off_t)position);
+
+    /*
+     * Deal with NBIO EAGAIN & EINTR the same as solaris. 
      */
     if (r == -1 || w == -1) {
-	fprintf(stderr, "%d %d %d %d %d\n", srcFD, dstFD, r, w, errno);
-	JNU_ThrowIOExceptionWithLastError(env, "Transfer failed");
-	return IOS_THROWN;
+        switch (errno) {
+	    case EAGAIN:
+	        return IOS_UNAVAILABLE;
+	    case EINTR:
+	        return IOS_INTERRUPTED;
+	    default:
+		JNU_ThrowIOExceptionWithLastError(env, "Transfer failed");
+		return IOS_THROWN;
+        }
     }
-    return (offset - (off_t)position);
+
+    return (0);
 #endif
 }
 

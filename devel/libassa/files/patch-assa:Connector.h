--- assa/Connector.h.orig	Wed Dec 24 17:32:49 2003
+++ assa/Connector.h	Wed Dec 24 17:34:16 2003
@@ -407,7 +407,7 @@
 	int error;
 	int ret;
 	error = ret = errno = 0;
-	size_t n = sizeof (error);
+	socklen_t n = sizeof (error);
 
 	/* Always remove IO handler first. */
 	m_reactor->removeHandler (this, WRITE_EVENT);	
@@ -415,7 +415,7 @@
 #if defined(linux)
 	ret = getsockopt (m_fd, SOL_SOCKET, SO_ERROR, (void*)&error, &n);
 #else  // Solaris 2.6 
-	ret = getsockopt (m_fd, SOL_SOCKET, SO_ERROR, (char*)&error, (int*)&n);
+	ret = getsockopt (m_fd, SOL_SOCKET, SO_ERROR, (char*)&error, &n);
 #endif
 
 	if (ret == 0) {

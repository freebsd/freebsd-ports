--- assa/Connector.h.orig	Tue Mar  1 20:40:39 2005
+++ assa/Connector.h	Tue Mar 22 20:13:07 2005
@@ -406,7 +406,7 @@
 	int error;
 	int ret;
 	error = ret = errno = 0;
-	size_t n = sizeof (error);
+	socklen_t n = sizeof (error);
 
 	/** Always remove IO handler first. 
 	 */

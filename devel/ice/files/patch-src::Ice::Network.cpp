--- src/Ice/Network.cpp.orig	Tue Oct 18 16:18:39 2005
+++ src/Ice/Network.cpp	Thu Nov 17 15:00:25 2005
@@ -275,7 +275,7 @@
 	{
 	    return;
 	}
-#elif defined(__APPLE__)
+#elif (defined(__APPLE__) || defined(__FreeBSD__))
 	if(errno == ENOTCONN || errno == EINVAL)
 	{
 	    return;
@@ -306,7 +306,7 @@
 	{
 	    return;
 	}
-#elif defined(__APPLE__)
+#elif (defined(__APPLE__) || defined(__FreeBSD__))
 	if(errno == ENOTCONN || errno == EINVAL)
 	{
 	    return;

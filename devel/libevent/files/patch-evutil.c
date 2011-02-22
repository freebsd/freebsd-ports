--- evutil.c.orig	2011-02-22 09:39:26.529403997 +0100
+++ evutil.c	2011-02-22 09:41:40.352952848 +0100
@@ -169,7 +169,7 @@
 	}
 #else
 	{
-		long flags;
+		int flags;
 		if ((flags = fcntl(fd, F_GETFL, NULL)) < 0) {
 			event_warn("fcntl(%d, F_GETFL)", fd);
 			return -1;

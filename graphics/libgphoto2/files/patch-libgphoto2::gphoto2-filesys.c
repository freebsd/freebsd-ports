--- libgphoto2/gphoto2-filesys.c.orig	Sun Jan 18 20:46:59 2004
+++ libgphoto2/gphoto2-filesys.c	Thu Jul 22 07:55:25 2004
@@ -1920,7 +1920,7 @@
 #elif HAVE_SYSCTL && (__FreeBSD__ || __NetBSD__ || __OpenBSD__ || __APPLE__ )
 
 	int mib[2] = { CTL_HW, HW_PHYSMEM };
-	int value;
+	unsigned long value;
 	size_t valuelen = sizeof(value);
 	*free=0;
 	if (sysctl(mib, 2 , &value, &valuelen, NULL, 0) == -1) {

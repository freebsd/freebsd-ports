--- cvsunix/lib/hostname.c.orig	Wed Nov 22 15:14:13 2006
+++ cvsunix/lib/hostname.c	Wed Nov 22 15:15:36 2006
@@ -28,6 +28,7 @@
 
 /* Put this host's name into NAME, using at most NAMELEN characters */
 
+#if 0
 int
 gethostname(name, namelen)
      char *name;
@@ -43,3 +44,4 @@
 
   return (0);
 }
+#endif

--- bfd/opncls.c.orig	2012-12-18 14:18:47.000000000 +0100
+++ bfd/opncls.c	2012-12-18 14:19:18.000000000 +0100
@@ -254,7 +254,7 @@
      then it may have been opened with special flags that make it
      unsafe to close and reopen the file.  */
   if (fd == -1)
-    bfd_set_cacheable (nbfd, TRUE);
+    (void)bfd_set_cacheable (nbfd, TRUE);
 
   return nbfd;
 }

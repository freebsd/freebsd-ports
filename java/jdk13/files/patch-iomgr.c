$FreeBSD$

--- ../src/solaris/hpi/green_threads/src/iomgr.c	Thu Mar 13 13:55:24 2003
+++ ../src/solaris/hpi/green_threads/src/iomgr.c	Thu Mar 13 13:55:53 2003
@@ -352,7 +352,6 @@
      * Get the ttyname, so we can reopen it.
      */
     name = ttyname(fd);
-    sysAssert(name != NULL);
     if (name == NULL)
 	return FALSE;
     

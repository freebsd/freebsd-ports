--- libportal/portal.c.orig	2022-03-21 19:20:46 UTC
+++ libportal/portal.c
@@ -27,7 +27,9 @@
 #include <string.h>
 #include <fcntl.h>
 #include <errno.h>
+#ifndef __FreeBSD__
 #include <sys/vfs.h>
+#endif
 #include <stdio.h>
 
 /**

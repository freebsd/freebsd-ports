--- ../cl/cl_read.c.orig	Fri Sep 15 18:37:07 2000
+++ ../cl/cl_read.c	Fri Sep 15 18:40:21 2000
@@ -15,7 +15,7 @@
 
 #include <sys/types.h>
 #include <sys/queue.h>
-#ifdef HAVE_SYS_SELECT_H
+#if 0
 #include <sys/select.h>
 #endif
 #include <sys/time.h>

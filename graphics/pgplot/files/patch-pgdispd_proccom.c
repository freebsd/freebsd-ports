--- pgdispd/proccom.c.orig	Sat Sep 28 23:09:02 2002
+++ pgdispd/proccom.c	Sat Sep 28 23:09:27 2002
@@ -93,7 +93,7 @@
 #include <sys/types.h>
 #include <netinet/in.h>
 
-#ifndef VMS
+#if !defined(VMS) && !defined(__FreeBSD__)
 #include <values.h>
 #endif
 

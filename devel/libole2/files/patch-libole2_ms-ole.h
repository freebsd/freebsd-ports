--- libole2/ms-ole.h.orig	Fri Sep 20 15:02:09 2002
+++ libole2/ms-ole.h	Fri Sep 20 15:02:56 2002
@@ -14,6 +14,7 @@
 /* This should be done in glib */
 #ifndef _WIN32
 #	include <fcntl.h>	/* for mode_t */
+#	include <sys/types.h>
 #else
 	typedef unsigned long mode_t;
 	typedef size_t ssize_t;

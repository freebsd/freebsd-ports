--- pathnames.h.orig	2020-10-18 03:01:26 UTC
+++ pathnames.h
@@ -35,3 +35,4 @@
 #include <paths.h>
 
 #define	_PATH_INCLUDE	"/usr/share/calendar"
+#define	_PATH_INCLUDE_LOCAL	_PATH_LOCALBASE "/share/calendar"

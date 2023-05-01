--- xcalendar.h.orig	1995-09-30 20:21:42.000000000 -0700
+++ xcalendar.h	2023-04-30 21:02:14.402254000 -0700
@@ -75,7 +75,7 @@
 #include <X11/Xaw/Xawi18n.h>
 #endif
 
-#if defined(SYSV) || defined(__osf__) || defined(SVR4)
+#if defined(SYSV) || defined(__osf__) || defined(SVR4) || defined(HAVE_DIRENT_H)
 #include <dirent.h>
 #else
 #include <sys/dir.h>

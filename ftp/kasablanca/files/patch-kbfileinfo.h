--- src/kbfileinfo.h.orig	Fri Jan 28 00:56:07 2005
+++ src/kbfileinfo.h	Wed Feb  2 23:17:14 2005
@@ -12,7 +12,12 @@
 #ifndef KBFILEINFO_H
 #define KBFILEINFO_H
 
+#include <fcntl.h>
 #include <qfileinfo.h>
+
+#ifdef __FreeBSD__
+#define off64_t off_t
+#endif
 
 class KbItem;
 

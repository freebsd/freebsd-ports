--- src/kbitem.h.orig	Fri Jan 28 00:56:07 2005
+++ src/kbitem.h	Wed Feb  2 23:38:36 2005
@@ -12,7 +12,12 @@
 #ifndef KBITEM_H
 #define KBITEM_H
 
+#include <fcntl.h>
 #include <qlistview.h>
+
+#ifdef __FreeBSD__
+#define off64_t off_t
+#endif
 
 class KbFileInfo;
 

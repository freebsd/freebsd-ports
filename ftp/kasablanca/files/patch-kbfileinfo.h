--- src/kbfileinfo.h.orig	Wed Aug 18 15:04:42 2004
+++ src/kbfileinfo.h	Wed Aug 18 15:06:10 2004
@@ -12,6 +12,7 @@
 #ifndef KBFILEINFO_H
 #define KBFILEINFO_H
 
+#include <fcntl.h>
 #include <qfileinfo.h>
 
 class KbItem;

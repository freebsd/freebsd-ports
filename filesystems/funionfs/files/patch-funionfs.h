--- funionfs.h.orig	Fri Jan 19 06:35:52 2007
+++ funionfs.h	Mon Apr 23 09:39:54 2007
@@ -21,6 +21,9 @@
 #ifndef _FUNIONFS_H
 #define _FUNIONFS_H
 
+#include <limits.h>
+#include <pthread.h>
+
 // use the new API
 
 #define VERSION "0.4.2"

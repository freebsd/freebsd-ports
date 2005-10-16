--- src/scivi.h.orig	Wed Jan 28 17:28:55 2004
+++ src/scivi.h	Fri Oct 14 21:46:01 2005
@@ -19,6 +19,7 @@
 #ifndef SCIVI_H
 #define SCIVI_H
 
+#include <pthread.h>
 #include <X11/Xlib.h>
 #include <gtk/gtk.h>
 #include "glstuff.h"

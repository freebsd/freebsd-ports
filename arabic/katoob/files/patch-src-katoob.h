--- src/katoob.h.orig	Thu May 20 12:44:35 2004
+++ src/katoob.h	Thu May 20 12:44:48 2004
@@ -25,11 +25,6 @@
 #ifndef __KATOOB_H__
 #define __KATOOB_H__
 
-#define G_DISABLE_DEPRECATED 1
-#define GDK_DISABLE_DEPRECATED 1
-#define GDK_PIXBUF_DISABLE_DEPRECATED 1
-#define GTK_DISABLE_DEPRECATED 1
-
 #include <gtk/gtk.h>
 #include "encodings.h"
 #ifdef ENABLE_HIGHLIGHT

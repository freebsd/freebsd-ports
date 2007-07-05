--- keymap.h.orig	Tue Sep 11 20:20:34 2001
+++ keymap.h	Wed Jul  4 18:17:25 2007
@@ -19,6 +19,8 @@
 #ifndef KEYMAP_H
 #define KEYMAP_H
 
+#include "mapping.h"
+
 /* maximal length of a key binding sequence used for buffer in km_bindkey */
 #define MAX_SEQ 8
 

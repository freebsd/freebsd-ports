--- src/chaser.c~	Tue May 12 05:43:03 1998
+++ src/chaser.c	Sat Nov 24 14:47:05 2001
@@ -20,7 +20,11 @@
 #include "pm.h"
 #include <X11/Xutil.h>
 #include <X11/keysym.h>
+#ifdef HAVE_STDLIB_H
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 #define MAX_MAPPED_STRING_LEN	20
 #define MAX_POPUP_STRING_LEN	40

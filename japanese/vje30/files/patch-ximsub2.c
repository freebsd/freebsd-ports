--- delta/newFrontend/ximsub2.c.orig	Wed May 22 16:26:06 2002
+++ delta/newFrontend/ximsub2.c	Tue May 28 18:52:57 2002
@@ -126,7 +126,11 @@
  */
 #include <stdio.h>
 #include <string.h>
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include "xim.h"
 #include <X11/Xatom.h>
 #include <X11/Xutil.h>

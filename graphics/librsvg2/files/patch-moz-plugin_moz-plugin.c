--- moz-plugin/moz-plugin.c.orig	Fri Sep  3 00:48:45 2004
+++ moz-plugin/moz-plugin.c	Fri Sep  3 00:49:35 2004
@@ -26,9 +26,12 @@
 #include <config.h>
 
 #include <stdio.h>
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include <unistd.h>
 #include <sys/wait.h>
+#include <signal.h>
 
 #include <X11/Xlib.h>
 #include <X11/Intrinsic.h>

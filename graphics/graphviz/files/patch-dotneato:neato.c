--- dotneato/neato.c.orig	Wed Feb  7 01:45:05 2001
+++ dotneato/neato.c	Tue Feb 27 06:49:23 2001
@@ -17,7 +17,9 @@
 #ifdef HAVE_CONFIG_H
 #include "gvconfig.h"
 #endif
+#ifndef DATE
 #include	"stamp.h"
+#endif
 #include	<time.h>
 #ifndef MSWIN32
 #include	<unistd.h>

--- dotneato/dot.c.orig	Wed Feb  7 01:44:19 2001
+++ dotneato/dot.c	Tue Feb 27 06:49:51 2001
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

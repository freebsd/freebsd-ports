--- play.c.orig	Sun Oct 22 04:13:35 1995
+++ play.c	Sat Jan 27 15:04:15 2001
@@ -36,7 +36,7 @@
 #include "dsp.h"
 
 #ifdef GUS
-#include <sys/ultrasound.h>
+#include <machine/ultrasound.h>
 #include "gus.h"
 #endif /* GUS */
 

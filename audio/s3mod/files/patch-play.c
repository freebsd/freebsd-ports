--- play.c.orig	1995-10-21 19:13:35 UTC
+++ play.c
@@ -36,7 +36,7 @@
 #include "dsp.h"
 
 #ifdef GUS
-#include <sys/ultrasound.h>
+#include <machine/ultrasound.h>
 #include "gus.h"
 #endif /* GUS */
 

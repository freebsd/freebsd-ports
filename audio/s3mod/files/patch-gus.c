--- gus.c.orig	1995-10-21 19:14:33 UTC
+++ gus.c
@@ -26,7 +26,7 @@
 #ifdef GUS
 
 #include <sys/soundcard.h>
-#include <sys/ultrasound.h>
+#include <machine/ultrasound.h>
 #include <unistd.h>
 #include "gus.h"
 #include "mod.h"

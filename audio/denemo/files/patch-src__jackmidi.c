--- src/jackmidi.c.orig	2009-08-24 03:03:26.000000000 +0900
+++ src/jackmidi.c	2009-09-28 15:42:09.000000000 +0900
@@ -8,6 +8,7 @@
 #include <math.h>
 #include <string.h>
 #include <assert.h>
+#include <sys/time.h>
 #include "exportmidi.h"
 #include "pitchentry.h"
 #include "smf.h"

--- src/jackmidi.c.orig	2011-04-27 19:59:45.083923000 +0200
+++ src/jackmidi.c	2011-05-07 10:44:07.000000000 +0200
@@ -7,6 +7,7 @@
 #include <math.h>
 #include <string.h>
 #include <assert.h>
+#include <sys/time.h>
 #include "exportmidi.h"
 #include "jackmidi.h"
 #include "pitchentry.h"

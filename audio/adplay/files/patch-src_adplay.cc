--- src/adplay.cc.orig	Fri May  6 19:23:17 2005
+++ src/adplay.cc	Fri May  6 19:23:24 2005
@@ -25,16 +25,15 @@
 #include <adplug/adplug.h>
 #include <adplug/emuopl.h>
 #include <adplug/kemuopl.h>
+#include <getopt.h>
 
 /*
- * Apple (OS X) and Sun systems declare getopt in unistd.h, other systems
- * (Linux) use getopt.h.
- */
 #if defined ( __APPLE__ ) || ( defined (__SVR4) && defined (__sun) )
 #       include <unistd.h>
 #else
 #       include "getopt.h"
 #endif
+*/
 
 #include "defines.h"
 #include "output.h"

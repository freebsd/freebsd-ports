--- src/lib/cp/unixcom.c.orig	2011-06-24 16:24:35.000000000 +0000
+++ src/lib/cp/unixcom.c	2011-06-24 16:30:47.000000000 +0000
@@ -6,6 +6,7 @@
 /*
  * Routines to do execution of unix commands.
  */
+#include <unistd.h>
 
 #include "spice.h"
 #include "cpdefs.h"

--- src/lib/cp/unixcom.c.orig	1993-04-14 01:15:50 UTC
+++ src/lib/cp/unixcom.c
@@ -6,6 +6,7 @@ Author: 1985 Wayne A. Christopher, U. C. Berkeley CAD 
 /*
  * Routines to do execution of unix commands.
  */
+#include <unistd.h>
 
 #include "spice.h"
 #include "cpdefs.h"

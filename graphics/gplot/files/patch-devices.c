--- devices.c.orig	Thu Jul 18 02:21:59 1991
+++ devices.c	Sat Jun 16 02:15:48 2007
@@ -1,5 +1,6 @@
 #include <stdio.h>
 #include <ctype.h>
+#include <string.h>
 #include "defs.h"
   /* this module contains one function, dev_setup, which is called by the main
      gplot modules at startup time. It is the only existing piece of code

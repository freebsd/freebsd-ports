--- converter/ppm/ppmtodjvurle.c.orig	Sun Mar 21 02:27:26 2004
+++ converter/ppm/ppmtodjvurle.c	Tue Mar 30 06:57:57 2004
@@ -33,7 +33,9 @@
 
 #include <stdio.h>
 #include <inttypes.h>
+#ifndef __FreeBSD__
 #include <netinet/in.h>
+#endif
 
 #include "ppm.h"
 #include "ppmcmap.h"

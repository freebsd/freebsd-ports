--- converter/other/infotopam.c.orig	Sat May  1 21:44:08 2004
+++ converter/other/infotopam.c	Thu Jul 22 19:19:16 2004
@@ -73,7 +73,9 @@
 #include "mallocvar.h"
 
 #include <errno.h>
+#ifndef __FreeBSD__
 #include <stdint.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

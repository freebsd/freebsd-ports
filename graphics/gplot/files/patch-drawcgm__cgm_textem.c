--- drawcgm/cgm_textem.c.orig	Thu Jul 18 02:22:32 1991
+++ drawcgm/cgm_textem.c	Sat Jun 16 02:09:15 2007
@@ -37,6 +37,7 @@
 #endif
 #ifdef USE_UNIX
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #endif
 #ifdef ardent

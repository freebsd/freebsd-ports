--- src/i386/icsprite.c.orig	Mon Jul 24 09:10:50 2006
+++ src/i386/icsprite.c	Wed Aug  9 19:11:00 2006
@@ -15,7 +15,8 @@
  *      See readme.txt for copyright information.
  */
 
-
+#include <machine/param.h>
+#include <sys/mman.h>
 #include <string.h>
 
 #include "allegro.h"

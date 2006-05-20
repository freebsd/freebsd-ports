--- clients/audio/autool/audiotool.c	Sun Jun 20 19:27:08 2004
+++ clients/audio/autool/audiotool.c	Mon Oct 10 11:24:41 2005
@@ -30,4 +30,5 @@
 #include "config.h"
 
+#include	<inttypes.h>
 #include	<stdio.h>
 
@@ -37,5 +38,5 @@
 
 #if defined(HAVE_MALLOC_H)
-# include <malloc.h>
+# include <stdlib.h>
 #endif
 
@@ -387,5 +388,5 @@
 {
     GlobalDataPtr   globals = (GlobalDataPtr) data;
-    int             position = (int) cd;
+    intptr_t        position = (intptr_t) cd;
     int             newVolume;
     char            buf[50];

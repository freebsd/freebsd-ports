--- clients/audio/autool/audiotool.c.orig	2013-10-07 17:05:48 UTC
+++ clients/audio/autool/audiotool.c
@@ -29,6 +29,7 @@
 
 #include "config.h"
 
+#include	<inttypes.h>
 #include <stdio.h>
 
 #if defined(HAVE_STDLIB_H)
@@ -36,7 +37,7 @@
 #endif
 
 #if defined(HAVE_MALLOC_H)
-# include <malloc.h>
+# include <stdlib.h>
 #endif
 
 #include <audio/audiolib.h>
@@ -366,7 +367,7 @@ static void
 scrollProcCB(Widget w, XtPointer data, XtPointer cd)
 {
     GlobalDataPtr   globals = (GlobalDataPtr) data;
-    int             position = (int) cd;
+    intptr_t        position = (intptr_t) cd;
     int             newVolume;
     char            buf[50];
 

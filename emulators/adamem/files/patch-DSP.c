--- DSP.c.orig	Mon Oct  7 20:23:32 2002
+++ DSP.c	Mon Oct  7 20:24:02 2002
@@ -15,7 +15,7 @@
 
 #include <stdio.h>
 #include <string.h>
-#include <values.h>
+#include <limits.h>
 
 static int initialised=0;
 static int stereo=0;
@@ -103,7 +103,7 @@
  if (freq>MAXFREQ)
   freq=MAXFREQ;
 
- if (freq>(MAXINT/441)) freq=MAXINT/441;        /* avoid overflows */
+ if (freq>(INT_MAX/441)) freq=INT_MAX/441;        /* avoid overflows */
  if (channel==3)
  {
   for (i=0;i<5;++i)

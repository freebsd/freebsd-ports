--- bonk.cc.orig	Sat Jun  2 02:06:22 2001
+++ bonk.cc	Sat Jun  2 02:07:11 2001
@@ -30,7 +30,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/ioctl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -41,6 +41,12 @@
 	      
 #include "utility.h"
 #include "wav.h"
+
+#if defined(_AIX) || defined(AIX)
+#  define AFMT_S16_NE AFMT_S16_BE
+#else
+#  define AFMT_S16_NE AFMT_S16_LE
+#endif
 
 //Accuracy of fixed point calculations
 const int lattice_shift  = 10,

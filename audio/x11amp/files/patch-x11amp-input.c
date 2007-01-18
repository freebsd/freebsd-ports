--- x11amp/input.c.orig	Thu Jan 18 01:29:04 2007
+++ x11amp/input.c	Thu Jan 18 01:30:03 2007
@@ -650,8 +650,8 @@
 #define LOG2_N_WAVE     10      /* log2(N_WAVE) */
 #define N_LOUD          100     /* dimension of Loudampl[] */
 
-extern fixed Sinewave[N_WAVE]; /* placed at end of this file for clarity */
-extern  fixed Loudampl[N_LOUD];
+static fixed Sinewave[N_WAVE]; /* placed at end of this file for clarity */
+static  fixed Loudampl[N_LOUD];
 static int db_from_ampl(fixed re, fixed im);
 static fixed fix_mpy(fixed a, fixed b);
 

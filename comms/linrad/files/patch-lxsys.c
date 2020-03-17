--- lxsys.c.orig	2014-11-04 10:25:00 UTC
+++ lxsys.c
@@ -63,7 +63,7 @@ int open_USB2LPT(void);
 
 struct termios old_options;
 #ifdef BSD
-char serport_name[]="/dev/ttyd....";
+char serport_name[]="/dev/ttyu....";
 #else
 char serport_name[]="/dev/ttyS....?";
 #endif
@@ -122,7 +122,6 @@ char *fht=" ht";
 char *fprocessor="processor";
 #endif
 int xxprint;
-int no_of_ht;
 // If there is no mmx, do not use simd either.
 tickspersec = sysconf(_SC_CLK_TCK);
 xxprint=0;
@@ -422,8 +421,8 @@ float lir_noisegen(int level) 
 // Return a number distributed following a gaussian
 // Mean value is 0 and sigma pow(2,level)
 float x, y, z; 
-y = (float)(random()+0.5)/RAND_MAX; 
-z = (float)(random()+0.5)/RAND_MAX; 
+y = (float)(random()+0.5)/(float)RAND_MAX; 
+z = (float)(random()+0.5)/(float)RAND_MAX; 
 x = z * 2*PI_L; 
 return sin(x)*sqrt(-2*log(y))*pow(2.,level);
 }
@@ -888,7 +887,7 @@ return port;
 
 float lir_random(void)
 {
-return (float)(random())/RAND_MAX; 
+return (float)(random())/(float)RAND_MAX; 
 }
 
 void lir_srandom(void)

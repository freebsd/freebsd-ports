--- src/gle/surface/ffitcontour.cpp.orig	2011-06-13 08:36:41 UTC
+++ src/gle/surface/ffitcontour.cpp
@@ -43,15 +43,9 @@
 
 /* "f2c.h" defines abs() -- conflict with the definition in <math.h> */
 /* changing the order solves the problem */
-#if ( defined(__OS2__) && defined(__EMX__) ) || defined(__WIN32__)
 #include <stdio.h>
 #include <math.h>
 #include "f2c.h"
-#else
-#include "f2c.h"
-#include <stdio.h>
-#include <math.h>
-#endif
 
 doublereal gutre2_(real* a, real* b);
 void gd_message__(const char *s, int l);

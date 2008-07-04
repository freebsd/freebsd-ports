--- src/TM_operators/mantiuk06/contrast_domain.cpp.orig	2008-04-28 18:15:22.000000000 +0200
+++ src/TM_operators/mantiuk06/contrast_domain.cpp	2008-07-04 12:49:16.000000000 +0200
@@ -41,8 +41,8 @@
 #include <string.h>
 #include <math.h>
 
-#ifdef WIN32
-#define exp10f( x ) exp( x * log (10))
+#if defined(WIN32) || defined(__FreeBSD__)
+#define exp10f(x) exp( (x) * log (10))
 #endif
 
 #include "contrast_domain.h"

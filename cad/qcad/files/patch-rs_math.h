--- qcadlib/src/math/rs_math.h.orig	Sat Aug 21 20:00:56 2004
+++ qcadlib/src/math/rs_math.h	Sat Aug 21 20:07:09 2004
@@ -45,8 +45,9 @@
 #include "rs_vector.h"
 
 #ifdef __GNUC__
-#define min(x,y) (x<y ? x : y)
-#define max(x,y) (x>y ? x : y)
+//#define min(x,y) (x<y ? x : y)
+//#define max(x,y) (x>y ? x : y)
+using namespace std;
 #endif
 
 #define ARAD 57.29577951308232

Fixes the build on 9.x:

/wrkdirs/usr/ports/graphics/hugin/work/hugin-2015.0.0/src/hugin_cpfind/localfeatures/RansacFiltering.cpp: In function 'int genint(int)':
/wrkdirs/usr/ports/graphics/hugin/work/hugin-2015.0.0/src/hugin_cpfind/localfeatures/RansacFiltering.cpp:28:31: error: 'rand' was not declared in this scope
     return (int)((double)rand()*x/(double)RAND_MAX);
                               ^
/wrkdirs/usr/ports/graphics/hugin/work/hugin-2015.0.0/src/hugin_cpfind/localfeatures/RansacFiltering.cpp:28:43: error: 'RAND_MAX' was not declared in this scope
     return (int)((double)rand()*x/(double)RAND_MAX);
                                           ^
--- src/hugin_cpfind/localfeatures/RansacFiltering.cpp.orig	2015-12-04 12:57:44 UTC
+++ src/hugin_cpfind/localfeatures/RansacFiltering.cpp
@@ -20,6 +20,7 @@
 
 #include "RansacFiltering.h"
 #include "Homography.h"
+#include <stdlib.h>
 
 using namespace std;
 

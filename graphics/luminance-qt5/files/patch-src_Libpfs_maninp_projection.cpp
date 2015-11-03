Include cstdio for stderr, to fix the build with gcc 4.9

--- src/Libpfs/manip/projection.cpp.orig	2015-10-29 16:26:58.000000000 +0100
+++ src/Libpfs/manip/projection.cpp	2015-10-29 16:27:41.000000000 +0100
@@ -26,6 +26,7 @@
 
 #include <cmath>
 #include <cstring>
+#include <cstdio>
 // #include <stdio.h>
 // #include <stdlib.h>
 

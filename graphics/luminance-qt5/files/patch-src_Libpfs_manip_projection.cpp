Include cstdio for stderr, to fix the build with gcc 4.9

--- src/Libpfs/manip/projection.cpp.orig	2021-01-11 09:41:28 UTC
+++ src/Libpfs/manip/projection.cpp
@@ -28,6 +28,7 @@
 
 #include <cmath>
 #include <cstring>
+#include <cstdio>
 // #include <stdio.h>
 // #include <stdlib.h>
 

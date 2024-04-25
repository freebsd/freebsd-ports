--- src/vector3.h.orig	2024-03-14 20:05:43 UTC
+++ src/vector3.h
@@ -8,6 +8,7 @@
 #include "vector2.h"
 #include <math.h>
 #include <stdio.h>
+#include <algorithm>
 
 // Need this pragma due to operator[] implementation.
 #pragma pack(4)

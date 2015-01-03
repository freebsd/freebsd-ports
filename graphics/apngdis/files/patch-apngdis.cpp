--- apngdis.cpp.orig	2015-01-03 02:18:00 UTC
+++ apngdis.cpp
@@ -30,6 +30,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <vector>
+#include <cstring>
 #include "png.h"     /* original (unpatched) libpng is ok */
 #include "zlib.h"
 using namespace std;

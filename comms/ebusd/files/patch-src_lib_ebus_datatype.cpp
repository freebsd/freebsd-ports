--- src/lib/ebus/datatype.cpp.orig	2023-06-07 06:49:34 UTC
+++ src/lib/ebus/datatype.cpp
@@ -22,6 +22,7 @@
 
 #include "lib/ebus/datatype.h"
 #include <math.h>
+#include <cmath> // Only required for FreeBSD 13.1, later versions seems to be fine without that
 #include <iostream>
 #include <sstream>
 #include <iomanip>

--- src/lib/ebus/datatype.cpp.orig	2023-07-08 13:54:20 UTC
+++ src/lib/ebus/datatype.cpp
@@ -22,6 +22,7 @@
 
 #include "lib/ebus/datatype.h"
 #include <math.h>
+#include <cmath> # for FreeBSD 12.4
 #include <iostream>
 #include <sstream>
 #include <iomanip>

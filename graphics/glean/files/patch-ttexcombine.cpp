--- glean/ttexcombine.cpp.orig	Thu Sep 25 16:17:52 2003
+++ glean/ttexcombine.cpp	Thu Sep 25 16:17:53 2003
@@ -75,6 +75,7 @@
 #include "ttexcombine.h"
 #include <stdio.h>
 #include <cmath>
+#include <cassert>
 
 #define CLAMP(VAL, MIN, MAX)	\
 	((VAL) < (MIN) ? (MIN) : ((VAL) > (MAX) ? (MAX) : (VAL)))

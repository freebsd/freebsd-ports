--- src/livarot/PathOutline.cpp.orig	Sat Oct 23 12:10:52 2004
+++ src/livarot/PathOutline.cpp	Fri Feb 18 00:28:16 2005
@@ -9,6 +9,7 @@
 #include "livarot/Path.h"
 #include "livarot/path-description.h"
 #include <cmath>
+#include <algorithm>
 #include <libnr/nr-point-fns.h>
 
 /*

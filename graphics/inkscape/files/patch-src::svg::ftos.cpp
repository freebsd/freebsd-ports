--- src/svg/ftos.cpp.orig	Sat Apr 10 04:00:08 2004
+++ src/svg/ftos.cpp	Sat Apr 10 03:59:33 2004
@@ -164,7 +164,7 @@
 using namespace std;
 
 #ifdef __FreeBSD__
-#include <stdio>
+#include <stdio.h>
 #endif
 
 #include "ftos.h"

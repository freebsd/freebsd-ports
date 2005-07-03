--- locator.cc.orig	Thu Jun 30 15:21:49 2005
+++ locator.cc	Thu Jun 30 17:04:24 2005
@@ -3,9 +3,13 @@
 /* Last change 29.07.2001  */

 /* A few includes */
-#include <iostream.h>
-#include <string.h>
-#include <stdio.h>
+#include <iostream>
+#include <cstdio>
+#include <cstring>
+
+using std::iostream;
+using std::ostream;
+using std::cout;

 /* A few definitions */
 #define VERSION "0.1"

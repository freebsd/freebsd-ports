--- src/pipe.cpp.orig	Sat Dec 24 18:19:31 2005
+++ src/pipe.cpp	Fri Aug  4 11:48:06 2006
@@ -25,9 +25,9 @@
 */
 
 #include <iostream>
-#include <stdlib.h>
+#include <cstdlib>
 #include <math.h>
-#include <errno.h>
+#include <cerrno>
 
 #include <audioproc.h>
 #include <pipe.h>

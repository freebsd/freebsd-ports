--- src/pipe.cpp.orig	Mon Dec  8 21:20:33 2003
+++ src/pipe.cpp	Mon Apr 19 22:39:37 2004
@@ -25,7 +25,8 @@
 */
 
 #include <iostream>
-#include <stdlib.h>
+#include <cstdlib>
+#include <cerrno>
 #include <audioproc.h>
 #include <pipe.h>
 #include <jutils.h>

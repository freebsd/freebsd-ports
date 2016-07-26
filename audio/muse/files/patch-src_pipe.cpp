--- src/pipe.cpp.orig	2005-12-24 15:19:31 UTC
+++ src/pipe.cpp
@@ -25,9 +25,9 @@ Boston, MA 02111-1307, USA.
 */
 
 #include <iostream>
-#include <stdlib.h>
+#include <cstdlib>
 #include <math.h>
-#include <errno.h>
+#include <cerrno>
 
 #include <audioproc.h>
 #include <pipe.h>

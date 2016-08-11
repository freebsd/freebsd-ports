--- apps/splay.cc.orig	2001-03-19 08:51:27 UTC
+++ apps/splay.cc
@@ -16,14 +16,15 @@
 
 #include <sys/types.h>
 #include <sys/wait.h>
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 #ifdef HAVE_LIBID3
 #include <id3/tag.h>
 #include <id3/misc_support.h>
 #endif /* HAVE_LIBID3 */
 
-#include <iomanip.h>
+#include <iomanip>
 
 #include "mpegsound.h"
 

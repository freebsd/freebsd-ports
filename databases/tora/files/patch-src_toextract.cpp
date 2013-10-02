--- src/toextract.cpp.orig	2010-02-02 18:25:43.000000000 +0000
+++ src/toextract.cpp
@@ -39,6 +39,7 @@
  *
  * END_COMMON_COPYRIGHT_HEADER */
 
+#include <unistd.h>
 #include "utils.h"
 
 #include "toconf.h"

--- src/ziphead.cpp.orig	Thu Jul 17 20:38:24 2003
+++ src/ziphead.cpp	Thu Jul 17 20:38:33 2003
@@ -2,6 +2,7 @@
 #include "zipios++/zipios-config.h"
 
 #include "zipios++/meta-iostreams.h"
+#include <assert.h>
 #include <iterator>
 #include <string>
 

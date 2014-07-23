--- src/tools.cpp.orig	2005-05-20 18:41:12.000000000 +0400
+++ src/tools.cpp	2014-07-23 02:57:51.000000000 +0400
@@ -14,6 +14,7 @@
 #include <sys/stat.h>
 #include <limits.h>
 #include <string.h>
+#include <unistd.h> // for access()
 
 #include "version.h"
 #include "PYFA.h"

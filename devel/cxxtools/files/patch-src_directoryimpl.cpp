--- src/directoryimpl.cpp.orig	2013-12-26 09:33:48 UTC
+++ src/directoryimpl.cpp
@@ -27,6 +27,7 @@
  */
 #include "directoryimpl.h"
 #include "cxxtools/systemerror.h"
+#include <sys/param.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <dirent.h>

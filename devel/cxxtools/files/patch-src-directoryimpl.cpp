--- a/src/directoryimpl.cpp
+++ b/src/directoryimpl.cpp
@@ -27,6 +27,7 @@
  */
 #include "directoryimpl.h"
 #include "cxxtools/systemerror.h"
+#include <sys/param.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <dirent.h>

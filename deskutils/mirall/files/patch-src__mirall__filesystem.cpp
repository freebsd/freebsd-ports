--- src/mirall/filesystem.cpp.orig
+++ src/mirall/filesystem.cpp
@@ -12,6 +12,7 @@
  */
 
 #include "filesystem.h"
+#include <sys/time.h>
 #include <QFile>
 #include <QDebug>
 

--- src/util/filesys.cc.orig	Fri Oct 31 20:53:31 2003
+++ src/util/filesys.cc	Fri Oct 31 20:55:05 2003
@@ -5,7 +5,9 @@
 #include "stringutil.h"
 #include "os.h"
 #include <unistd.h>
+#include <errno.h>
 #include <stdexcept>
+#include <memory>
 
 using std::string;
 

--- src/util/filesys.cc.orig	Sat Jan 17 23:18:22 2004
+++ src/util/filesys.cc	Sat Jan 17 23:19:26 2004
@@ -4,6 +4,8 @@
 #include "filesys.h"
 #include "stringutil.h"
 #include "os.h"
+#include <errno.h>
+#include <memory>
 #include <unistd.h>
 #include <stdexcept>
 #include "defines.h"

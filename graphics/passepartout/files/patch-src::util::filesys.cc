--- src/util/filesys.cc.orig	Thu Oct 30 22:42:31 2003
+++ src/util/filesys.cc	Fri Nov 21 16:31:15 2003
@@ -6,11 +6,13 @@
 #include "os.h"
 #include <unistd.h>
 #include <stdexcept>
+#include <memory>
 #include "defines.h"
 #ifndef HAVE_MKDTEMP
 #include <sys/types.h>
 #include <sys/stat.h>
 #endif
+#include <errno.h>
 
 using std::string;
 

--- common/plfilesrc.cpp.orig	Fri Jun 18 20:46:59 2004
+++ common/plfilesrc.cpp	Fri Jun 18 20:47:16 2004
@@ -17,9 +17,9 @@
 #include "plexcept.h"
 
 #ifdef HAVE_MMAP
+#include <sys/types.h>
 #include <sys/mman.h>
 #include <sys/stat.h>
-#include <sys/types.h>
 #include <fcntl.h>
 #include <unistd.h>
 #endif

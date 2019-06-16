--- ExternalLibs/ttvfs/VFSTools.cpp.orig	2016-06-19 23:56:27 UTC
+++ ExternalLibs/ttvfs/VFSTools.cpp
@@ -12,11 +12,7 @@
 #   include <windows.h>
 #   include <io.h>
 #else
-#  ifdef __HAIKU__
-#    include <dirent.h>
-#  else
-#    include <sys/dir.h>
-#  endif
+#  include <dirent.h>
 #  include <unistd.h>
 #endif
 

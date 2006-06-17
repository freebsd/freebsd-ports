--- ./src/common/vfs/vfs_mapped_arena.cpp.orig	Sun Mar  6 09:04:32 2005
+++ ./src/common/vfs/vfs_mapped_arena.cpp	Fri Jun 16 21:53:31 2006
@@ -55,6 +55,7 @@
 #include <sys/mman.h>
 #endif
 #include <sys/types.h>
+#include <sys/stat.h>
 #include <fcntl.h>
 #include <map>
 #include <cerrno>

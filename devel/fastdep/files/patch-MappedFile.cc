--- MappedFile.cc.orig	Wed May  3 18:30:46 2006
+++ MappedFile.cc	Wed May  3 18:30:12 2006
@@ -5,6 +5,7 @@
 #define PATH_MAX MAX_PATH
 #else
 #include <sys/mman.h>
+#include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
 

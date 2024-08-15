--- folly/debugging/symbolizer/Elf.cpp.orig	2024-02-16 02:33:47 UTC
+++ folly/debugging/symbolizer/Elf.cpp
@@ -19,6 +19,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <unistd.h>
 #include <cstring>
 #include <string>
 

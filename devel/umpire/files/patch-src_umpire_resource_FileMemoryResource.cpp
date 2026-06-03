--- src/umpire/resource/FileMemoryResource.cpp.orig	2025-09-09 19:07:47 UTC
+++ src/umpire/resource/FileMemoryResource.cpp
@@ -12,6 +12,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/mman.h>
+#include <sys/stat.h>
 #include <unistd.h>
 
 #include "umpire/util/Platform.hpp"
@@ -62,7 +63,7 @@ void* FileMemoryResource::allocate(std::size_t bytes)
   ss << default_dir << "umpire_mem_" << getpid() << "_" << s_file_counter;
   s_file_counter++;
 
-  int fd{open(ss.str().c_str(), O_RDWR | O_CREAT | O_LARGEFILE, S_IRWXU)};
+  int fd{open(ss.str().c_str(), O_RDWR | O_CREAT, S_IRWXU)};
   if (fd == -1) {
     UMPIRE_ERROR(runtime_error, fmt::format("Opening file {} failed: {}", ss.str(), strerror(errno)));
   }

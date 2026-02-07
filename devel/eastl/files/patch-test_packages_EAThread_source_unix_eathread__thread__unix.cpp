--- test/packages/EAThread/source/unix/eathread_thread_unix.cpp.orig	2023-07-26 16:30:35 UTC
+++ test/packages/EAThread/source/unix/eathread_thread_unix.cpp
@@ -10,6 +10,8 @@
 #include <eathread/eathread_sync.h>
 #include "eathread/internal/eathread_global.h"
 
+#include <unistd.h>
+
 
 #if defined(EA_PLATFORM_UNIX) || EA_POSIX_THREADS_AVAILABLE
     #include <new>

--- test/packages/EAThread/source/unix/eathread_pthread_stack_info.cpp.orig	2023-07-26 16:32:58 UTC
+++ test/packages/EAThread/source/unix/eathread_pthread_stack_info.cpp
@@ -5,6 +5,7 @@
 
 #include <eathread/eathread_callstack.h>
 #include <stdlib.h>
+#include <pthread_np.h>
 
 #if defined(EA_PLATFORM_UNIX) || defined(EA_PLATFORM_APPLE)
 	#include <pthread.h>

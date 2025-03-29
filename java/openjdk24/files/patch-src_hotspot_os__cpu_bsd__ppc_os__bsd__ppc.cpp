--- src/hotspot/os_cpu/bsd_ppc/os_bsd_ppc.cpp.orig	2024-04-11 22:23:08 UTC
+++ src/hotspot/os_cpu/bsd_ppc/os_bsd_ppc.cpp
@@ -61,6 +61,7 @@
 # include <sys/types.h>
 # include <sys/mman.h>
 # include <pthread.h>
+# include <pthread_np.h>
 # include <signal.h>
 # include <errno.h>
 # include <dlfcn.h>
@@ -432,6 +433,33 @@ size_t os::Posix::default_stack_size(os::ThreadType th
   // Default stack size (compiler thread needs larger stack).
   size_t s = (thr_type == os::compiler_thread ? 4 * M : 1024 * K);
   return s;
+}
+
+void os::current_stack_base_and_size(address* base, size_t* size) {
+  address bottom;
+  pthread_attr_t attr;
+
+  int rslt = pthread_attr_init(&attr);
+
+  // JVM needs to know exact stack location, abort if it fails  
+  if (rslt != 0)
+    fatal("pthread_attr_init failed with error = %d", rslt);
+
+  rslt = pthread_attr_get_np(pthread_self(), &attr);
+
+  if (rslt != 0)
+    fatal("pthread_attr_get_np failed with error = %d", rslt);
+
+  if (pthread_attr_getstackaddr(&attr, (void **)&bottom) != 0 ||
+      pthread_attr_getstacksize(&attr, size) != 0) {
+    fatal("Can not locate current stack attributes!");
+  }
+
+  *base = bottom + *size;
+
+  pthread_attr_destroy(&attr);
+  assert(os::current_stack_pointer() >= bottom &&
+         os::current_stack_pointer() < *base, "just checking");
 }
 
 /////////////////////////////////////////////////////////////////////////////

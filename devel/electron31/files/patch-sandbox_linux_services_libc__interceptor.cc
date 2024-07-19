--- sandbox/linux/services/libc_interceptor.cc.orig	2024-06-18 21:43:37 UTC
+++ sandbox/linux/services/libc_interceptor.cc
@@ -12,7 +12,9 @@
 #include <stddef.h>
 #include <stdint.h>
 #include <string.h>
+#if !BUILDFLAG(IS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <time.h>
@@ -168,7 +170,7 @@ bool ReadTimeStruct(base::PickleIterator* iter,
   } else {
     base::AutoLock lock(g_timezones_lock.Get());
     auto ret_pair = g_timezones.Get().insert(timezone);
-    output->tm_zone = ret_pair.first->c_str();
+    output->tm_zone = (char *)ret_pair.first->c_str();
   }
 
   return true;

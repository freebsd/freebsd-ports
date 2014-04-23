--- software/crash_handling/StackWalker.cpp.orig	2014-04-22 16:44:05.000000000 +0200
+++ software/crash_handling/StackWalker.cpp	2014-04-22 16:46:01.000000000 +0200
@@ -255,8 +255,13 @@
       char * real_name = abi::__cxa_demangle(mangled_name, 0, 0, &status);
 
       char *end;
+#if defined(__FreeBSD__) && __FreeBSD_version < 9000000
+      int64_t runtimeAddr = static_cast<int64_t>(strtol(runtime_addr, &end, 16));
+      int64_t runtimeOffset = static_cast<int64_t>(strtol(runtime_offset, &end, 0));
+#else
       int64_t runtimeAddr = static_cast<int64_t>(strtoll(runtime_addr, &end, 16));
       int64_t runtimeOffset = static_cast<int64_t>(strtoll(runtime_offset, &end, 0));
+#endif
 
       if (runtimeAddr == 1 && i == (size - 1))
         break;

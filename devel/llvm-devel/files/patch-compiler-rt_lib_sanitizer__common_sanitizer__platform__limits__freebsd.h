--- compiler-rt/lib/sanitizer_common/sanitizer_platform_limits_freebsd.h.orig
+++ compiler-rt/lib/sanitizer_common/sanitizer_platform_limits_freebsd.h
@@ -717,7 +717,11 @@
 extern unsigned struct_StringList_sz;
 
 struct __sanitizer_cpuset {
+#if __FreeBSD_version >= 1400090
+  long __bits[(1024 + (sizeof(long) * 8) - 1) / (sizeof(long) * 8)];
+#else
   long __bits[(256 + (sizeof(long) * 8) - 1) / (sizeof(long) * 8)];
+#endif
 };
 
 typedef struct __sanitizer_cpuset __sanitizer_cpuset_t;

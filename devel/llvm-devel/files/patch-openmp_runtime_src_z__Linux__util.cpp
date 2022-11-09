--- openmp/runtime/src/z_Linux_util.cpp.orig
+++ openmp/runtime/src/z_Linux_util.cpp
@@ -130,14 +130,14 @@
 #elif KMP_OS_FREEBSD
 #define KMP_CPU_SET_SIZE_LIMIT (sizeof(cpuset_t))
 #endif
+  int verbose = __kmp_affinity.flags.verbose;
+  int warnings = __kmp_affinity.flags.warnings;
+  enum affinity_type type = __kmp_affinity.type;
 
 #if KMP_OS_LINUX
   long gCode;
   unsigned char *buf;
   buf = (unsigned char *)KMP_INTERNAL_MALLOC(KMP_CPU_SET_SIZE_LIMIT);
-  int verbose = __kmp_affinity.flags.verbose;
-  int warnings = __kmp_affinity.flags.warnings;
-  enum affinity_type type = __kmp_affinity.type;
 
   // If the syscall returns a suggestion for the size,
   // then we don't have to search for an appropriate size.

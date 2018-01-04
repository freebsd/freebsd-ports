--- hotspot/src/os/bsd/vm/globals_bsd.hpp.orig	2014-03-04 02:52:13 UTC
+++ hotspot/src/os/bsd/vm/globals_bsd.hpp
@@ -35,19 +35,17 @@
   product(bool, UseBsdPosixThreadCPUClocks, true,                     \
           "enable fast Bsd Posix clocks where available")             \
 /*  NB: The default value of UseBsdPosixThreadCPUClocks may be        \
-    overridden in Arguments::parse_each_vm_init_arg.  */                \
-                                                                        \
-  product(bool, UseHugeTLBFS, false,                                    \
-          "Use MAP_HUGETLB for large pages")                            \
-                                                                        \
-  product(bool, UseSHM, false,                                          \
-          "Use SYSV shared memory for large pages")
+    overridden in Arguments::parse_each_vm_init_arg.  */
 
 //
 // Defines Bsd-specific default values. The flags are available on all
 // platforms, but they may have different default values on other platforms.
 //
+#ifdef __FreeBSD__
+define_pd_global(bool, UseLargePages, true);
+#else
 define_pd_global(bool, UseLargePages, false);
+#endif
 define_pd_global(bool, UseLargePagesIndividualAllocation, false);
 define_pd_global(bool, UseOSErrorReporting, false);
 define_pd_global(bool, UseThreadPriorities, true) ;

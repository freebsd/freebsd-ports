--- include/tbb/tbb_config.h.orig	2019-12-18 22:42:41 UTC
+++ include/tbb/tbb_config.h
@@ -677,6 +677,10 @@ There are four cases that are supported:
         However these functions are not defined anywhere. It seems that this problem was fixed later on
         and RHEL got an updated version of gcc 4.1.2. **/
     #define __TBB_GCC_64BIT_ATOMIC_BUILTINS_BROKEN 1
+#elif __TBB_x86_32 && __TBB_GCC_VERSION == 40201 && !__clang__ && __FreeBSD__
+    /** Symbol '__sync_val_compare_and_swap_8' not defined
+        on FreeBSD 8.4/i386 and 9.2/i386 with base gcc **/
+    #define __TBB_GCC_64BIT_ATOMIC_BUILTINS_BROKEN 1
 #endif
 
 #if __GNUC__ && __TBB_x86_64 && __INTEL_COMPILER == 1200

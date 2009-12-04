--- boost/smart_ptr/detail/sp_counted_base_gcc_sparc.hpp.orig	2009-11-26 07:22:29.000000000 -0500
+++ boost/smart_ptr/detail/sp_counted_base_gcc_sparc.hpp	2009-11-26 07:24:36.000000000 -0500
@@ -30,9 +30,9 @@
 
 inline int32_t compare_and_swap( int32_t * dest_, int32_t compare_, int32_t swap_ )
 {
-    __asm__ __volatile__( "cas %0, %2, %1"
-                        : "+m" (*dest_), "+r" (swap_)
-                        : "r" (compare_)
+    __asm__ __volatile__( "cas [%1], %2, %0"
+                        : "+r" (swap_)
+                        : "r" (dest_), "r" (compare_)
                         : "memory" );
 
     return swap_;

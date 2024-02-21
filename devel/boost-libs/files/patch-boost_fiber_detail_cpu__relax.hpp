--- boost/fiber/detail/cpu_relax.hpp.orig	2024-02-21 21:22:18 UTC
+++ boost/fiber/detail/cpu_relax.hpp
@@ -59,7 +59,7 @@ namespace detail {
 //               processors
 // extended mnemonics (available with POWER7)
 // yield   ==   or 27, 27, 27
-# if defined(__POWERPC__) // Darwin PPC
+# if defined(__APPLE__) // Darwin PPC
 # define cpu_relax() asm volatile ("or r27,r27,r27" ::: "memory");
 # else
 # define cpu_relax() asm volatile ("or 27,27,27" ::: "memory");

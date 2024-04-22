--- compiler-rt/lib/sanitizer_common/sanitizer_linux_libcdep.cpp.orig
+++ compiler-rt/lib/sanitizer_common/sanitizer_linux_libcdep.cpp
@@ -53,7 +53,7 @@
 // that, it was never implemented. So just define it to zero.
 #    undef MAP_NORESERVE
 #    define MAP_NORESERVE 0
-extern const Elf_Auxinfo *__elf_aux_vector;
+extern const Elf_Auxinfo *__elf_aux_vector __attribute__ ((weak));
 #  endif
 
 #  if SANITIZER_NETBSD

--- src/runtime/ppc-arch.c.orig
+++ src/runtime/ppc-arch.c
@@ -616,7 +616,9 @@
   // but trick the compiler into thinking it isn't, so that it does not
   // indirect through a descriptor, but instead we get its logical address.
   if (target_addr != &call_into_c) {
-#ifdef LISP_FEATURE_LITTLE_ENDIAN
+#ifndef LISP_FEATURE_PPC64_ELFV1
+      /* ELFv2: no function descriptors, so the linkage entry is an inline
+       * jump that materializes the target address in r12 and branches to it. */
       int* inst_ptr;
       unsigned long a0,a16,a32,a48;
       unsigned int inst;
@@ -670,7 +672,7 @@
       os_flush_icache((os_vm_address_t) reloc_addr, (char*) inst_ptr - reloc_addr);
 
 #else
-      // Could use either ABI, but we're assuming v1
+      /* ELFv1: function pointers are descriptors, as detailed below. */
       /* In the 64-bit v1 ABI, function pointers are alway passed around
        * as "function descriptors", not directly the jump target address.
        * A descriptor is 3 words:

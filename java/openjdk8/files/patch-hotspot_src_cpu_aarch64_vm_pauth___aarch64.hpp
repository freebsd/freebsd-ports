--- hotspot/src/cpu/aarch64/vm/pauth_aarch64.hpp
+++ hotspot/src/cpu/aarch64/vm/pauth_aarch64.hpp
@@ -25,7 +25,11 @@
 #ifndef CPU_AARCH64_PAUTH_AARCH64_INLINE_HPP
 #define CPU_AARCH64_PAUTH_AARCH64_INLINE_HPP
 
+#if defined(LINUX)
 #include "pauth_linux_aarch64.inline.hpp"
+#elif defined(_ALLBSD_SOURCE)
+#include "pauth_bsd_aarch64.inline.hpp"
+#endif
 
 inline bool pauth_ptr_is_raw(address ptr) {
   // Confirm none of the high bits are set in the pointer.

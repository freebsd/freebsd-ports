
# HG changeset patch
# User Stefan Krah <skrah@bytereef.org>
# Date 1356273741 -3600
# Node ID f05d29353f0278b21295f44467d08bd57a9ae33f
# Parent  e684b253fd9dd73495fcef89aad43ae9c42f975c
Issue #16753: Define __GNUC_STDC_INLINE__ to an integer (same as gcc).

diff --git a/Modules/_decimal/libmpdec/mpdecimal.h b/Modules/_decimal/libmpdec/mpdecimal.h
--- Modules/_decimal/libmpdec/mpdecimal.h
+++ Modules/_decimal/libmpdec/mpdecimal.h
@@ -63,7 +63,7 @@ extern "C" {
     #include <inttypes.h>
   #endif
   #ifndef __GNUC_STDC_INLINE__
-    #define __GNUC_STDC_INLINE__
+    #define __GNUC_STDC_INLINE__ 1
   #endif
   #if defined(__GNUC__) && !defined(__INTEL_COMPILER)
     #define UNUSED __attribute__((unused))


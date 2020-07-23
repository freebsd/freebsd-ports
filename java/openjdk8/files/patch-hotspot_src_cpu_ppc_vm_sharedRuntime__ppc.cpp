--- hotspot/src/cpu/ppc/vm/sharedRuntime_ppc.cpp
+++ hotspot/src/cpu/ppc/vm/sharedRuntime_ppc.cpp
@@ -42,7 +42,11 @@
 #include "opto/runtime.hpp"
 #endif
 
+#ifdef _ALLBSD_SOURCE
+#include <stdlib.h>
+#else
 #include <alloca.h>
+#endif
 
 #define __ masm->
 

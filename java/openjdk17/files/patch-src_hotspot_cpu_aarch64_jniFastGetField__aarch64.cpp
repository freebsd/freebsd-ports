--- src/hotspot/cpu/aarch64/jniFastGetField_aarch64.cpp
+++ src/hotspot/cpu/aarch64/jniFastGetField_aarch64.cpp
@@ -31,6 +31,7 @@
 #include "prims/jniFastGetField.hpp"
 #include "prims/jvm_misc.hpp"
 #include "prims/jvmtiExport.hpp"
+#include "runtime/thread.inline.hpp"
 #include "runtime/safepoint.hpp"
 #include "runtime/threadWXSetters.inline.hpp"
 

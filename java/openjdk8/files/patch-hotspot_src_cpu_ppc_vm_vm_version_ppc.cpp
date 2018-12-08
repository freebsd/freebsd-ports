--- hotspot/src/cpu/ppc/vm/vm_version_ppc.cpp.orig
+++ hotspot/src/cpu/ppc/vm/vm_version_ppc.cpp
@@ -38,8 +38,13 @@
 #ifdef TARGET_OS_FAMILY_linux
 # include "os_linux.inline.hpp"
 #endif
-
+#ifdef TARGET_OS_FAMILY_bsd
+# include "os_bsd.inline.hpp"
+#endif
+
+#ifndef TARGET_OS_FAMILY_bsd
 # include <sys/sysinfo.h>
+#endif
 
 int VM_Version::_features = VM_Version::unknown_m;
 int VM_Version::_measured_cache_line_size = 128; // default value

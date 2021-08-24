--- mlir/lib/ExecutionEngine/CRunnerUtils.cpp.orig
+++ mlir/lib/ExecutionEngine/CRunnerUtils.cpp
@@ -15,10 +15,14 @@
 #include "mlir/ExecutionEngine/CRunnerUtils.h"
 
 #ifndef _WIN32
-#include <alloca.h>
-#include <sys/time.h>
+# if defined(__FreeBSD__) || defined(__NetBSD__)
+#  include <cstdlib>
+# else
+#  include <alloca.h>
+# endif
+# include <sys/time.h>
 #else
-#include "malloc.h"
+# include "malloc.h"
 #endif // _WIN32
 
 #include <cinttypes>

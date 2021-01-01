--- gpu/command_buffer/service/program_manager.cc.orig	2019-03-15 06:37:24 UTC
+++ gpu/command_buffer/service/program_manager.cc
@@ -31,7 +31,11 @@
 #include "gpu/command_buffer/service/progress_reporter.h"
 #include "gpu/command_buffer/service/shader_manager.h"
 #include "gpu/config/gpu_preferences.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "ui/gl/gl_version_info.h"
 
 using base::TimeDelta;

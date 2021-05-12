--- gpu/config/gpu_control_list.cc.orig	2021-04-14 01:08:50 UTC
+++ gpu/config/gpu_control_list.cc
@@ -18,7 +18,11 @@
 #include "build/build_config.h"
 #include "build/chromeos_buildflags.h"
 #include "gpu/config/gpu_util.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif // defined(OS_BSD)
 
 namespace gpu {
 namespace {
@@ -276,7 +280,7 @@ bool GpuControlList::More::GLVersionInfoMismatch(
 GpuControlList::GLType GpuControlList::More::GetDefaultGLType() {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   return kGLTypeGL;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kGLTypeGL;
 #elif defined(OS_MAC)
   return kGLTypeGL;
@@ -782,7 +786,7 @@ GpuControlList::OsType GpuControlList::GetOsType() {
   return kOsAndroid;
 #elif defined(OS_FUCHSIA)
   return kOsFuchsia;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kOsLinux;
 #elif defined(OS_MAC)
   return kOsMacosx;

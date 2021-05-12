--- base/util/memory_pressure/system_memory_pressure_evaluator.cc.orig	2021-04-14 01:08:36 UTC
+++ base/util/memory_pressure/system_memory_pressure_evaluator.cc
@@ -17,7 +17,7 @@
 #include "base/win/windows_version.h"
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "base/util/memory_pressure/system_memory_pressure_evaluator_linux.h"
 #endif
 
@@ -50,7 +50,7 @@ SystemMemoryPressureEvaluator::CreateDefaultSystemEval
   return evaluator;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   return std::make_unique<util::os_linux::SystemMemoryPressureEvaluator>(
       monitor->CreateVoter());
 #endif

--- src/utils/arch_features.h.orig	2026-05-05 07:10:32 UTC
+++ src/utils/arch_features.h
@@ -6,10 +6,10 @@
 #ifndef ARCH_FEATURES_H
 #define ARCH_FEATURES_H

-#include "cpu_features/include/cpu_features_macros.h"
+#include <cpu_features/cpu_features_macros.h>

 #ifdef CPU_FEATURES_ARCH_X86_64
-#include "cpu_features/include/cpuinfo_x86.h"
+#include <cpu_features/cpuinfo_x86.h>
 #else
 typedef struct X86Features
 {

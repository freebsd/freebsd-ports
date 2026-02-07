- workaround for https://github.com/secure-software-engineering/phasar/issues/562

--- include/phasar/PhasarLLVM/ControlFlow/Resolver/RTAResolver.h.orig	2024-03-02 09:55:57 UTC
+++ include/phasar/PhasarLLVM/ControlFlow/Resolver/RTAResolver.h
@@ -17,6 +17,8 @@
 #ifndef PHASAR_PHASARLLVM_CONTROLFLOW_RESOLVER_RTARESOLVER_H_
 #define PHASAR_PHASARLLVM_CONTROLFLOW_RESOLVER_RTARESOLVER_H_
 
+#include <vector>
+
 #include "phasar/PhasarLLVM/ControlFlow/Resolver/CHAResolver.h"
 
 #include <vector>

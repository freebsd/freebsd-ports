--- src/core/lib/surface/wait_for_cq_end_op.cc.orig	2024-02-20 20:23:19 UTC
+++ src/core/lib/surface/wait_for_cq_end_op.cc
@@ -14,6 +14,7 @@
 
 #include <grpc/support/port_platform.h>
 
+#include "absl/strings/str_format.h"
 #include "src/core/lib/surface/wait_for_cq_end_op.h"
 
 #include <atomic>
@@ -72,4 +73,4 @@ std::string WaitForCqEndOp::StateString(const State& s
       [](const Invalid&) -> std::string { return "Invalid{}"; });
 }
 
-}  // namespace grpc_core
\ No newline at end of file
+}  // namespace grpc_core

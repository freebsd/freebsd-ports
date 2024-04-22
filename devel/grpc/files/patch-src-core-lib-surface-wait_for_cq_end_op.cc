--- src/core/lib/surface/wait_for_cq_end_op.cc.orig	2024-03-08 01:33:47 UTC
+++ src/core/lib/surface/wait_for_cq_end_op.cc
@@ -12,6 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
+#include <absl/strings/str_format.h>
 #include <grpc/support/port_platform.h>
 
 #include "src/core/lib/surface/wait_for_cq_end_op.h"
@@ -72,4 +73,4 @@ std::string WaitForCqEndOp::StateString(const State& s
       [](const Invalid&) -> std::string { return "Invalid{}"; });
 }
 
-}  // namespace grpc_core
\ No newline at end of file
+}  // namespace grpc_core

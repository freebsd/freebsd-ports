Include ryml_std.hpp with the system rapidyaml. It defines the std::string
helpers, for example c4::to_csubstr(), that vm.cpp uses. The bundled
single header already contains them.

Obtained from:	https://github.com/google/jsonnet/commit/93ed3ccac2

--- core/vm.cpp.orig	2026-03-24 14:14:29 UTC
+++ core/vm.cpp
@@ -31,6 +31,7 @@ limitations under the License.
 #include "parser.h"
 #ifdef USE_SYSTEM_RAPIDYAML
 #include <ryml.hpp>
+#include <ryml_std.hpp>
 #else
 #include "rapidyaml-0.10.0.hpp"
 #endif

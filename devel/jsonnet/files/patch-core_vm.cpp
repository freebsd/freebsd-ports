--- core/vm.cpp.orig	2021-06-20 03:31:11 UTC
+++ core/vm.cpp
@@ -23,7 +23,7 @@ limitations under the License.
 
 #include "desugarer.h"
 #include "json.h"
-#include "json.hpp"
+#include "nlohmann/json.hpp"
 #include "md5.h"
 #include "parser.h"
 #include "state.h"

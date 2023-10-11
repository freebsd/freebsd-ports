--- core/vm.cpp.orig	2023-04-17 19:02:16 UTC
+++ core/vm.cpp
@@ -23,7 +23,7 @@ limitations under the License.
 
 #include "desugarer.h"
 #include "json.h"
-#include "json.hpp"
+#include "nlohmann/json.hpp"
 #include "md5.h"
 #include "parser.h"
 #include "ryml_std.hpp" // include this before any other ryml header
@@ -1710,6 +1710,10 @@ class Interpreter {
             } break;
 
             case json::value_t::discarded: {
+                abort();
+            }
+
+            case json::value_t::binary: {
                 abort();
             }
         }

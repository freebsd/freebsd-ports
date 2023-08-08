--- fdbserver/FDBExecHelper.actor.cpp.orig	2022-09-19 11:42:41 UTC
+++ fdbserver/FDBExecHelper.actor.cpp
@@ -18,6 +18,14 @@
  * limitations under the License.
  */
 
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__INTEL_COMPILER)
+#define BOOST_SYSTEM_NO_LIB
+#define BOOST_DATE_TIME_NO_LIB
+#define BOOST_REGEX_NO_LIB
+#include <boost/process.hpp>
+#endif
+#include <boost/algorithm/string.hpp>
+
 #include "flow/TLSConfig.actor.h"
 #include "flow/Trace.h"
 #include "flow/Platform.h"
@@ -33,14 +41,6 @@
 #include "fdbserver/FDBExecHelper.actor.h"
 #include "fdbserver/Knobs.h"
 #include "fdbserver/RemoteIKeyValueStore.actor.h"
-
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__INTEL_COMPILER)
-#define BOOST_SYSTEM_NO_LIB
-#define BOOST_DATE_TIME_NO_LIB
-#define BOOST_REGEX_NO_LIB
-#include <boost/process.hpp>
-#endif
-#include <boost/algorithm/string.hpp>
 
 #include "flow/actorcompiler.h" // This must be the last #include.
 

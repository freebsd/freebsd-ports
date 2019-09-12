--- adb/bugreport_test.cpp.orig	2019-08-13 02:10:58 UTC
+++ adb/bugreport_test.cpp
@@ -14,8 +14,6 @@
  * limitations under the License.
  */
 
-#include "bugreport.h"
-
 #include <gmock/gmock.h>
 #include <gtest/gtest.h>
 
@@ -24,6 +22,7 @@
 
 #include "sysdeps.h"
 #include "adb_utils.h"
+#include "bugreport.h"
 
 using ::testing::_;
 using ::testing::Action;
@@ -40,6 +39,7 @@ using ::testing::internal::CaptureStdout;
 using ::testing::internal::GetCapturedStderr;
 using ::testing::internal::GetCapturedStdout;
 
+#ifdef __linux__
 // Empty function so tests don't need to be linked against file_sync_service.cpp, which requires
 // SELinux and its transitive dependencies...
 bool do_sync_pull(const std::vector<const char*>& srcs, const char* dst, bool copy_attrs,
@@ -47,6 +47,7 @@ bool do_sync_pull(const std::vector<const char*>& srcs
     ADD_FAILURE() << "do_sync_pull() should have been mocked";
     return false;
 }
+#endif
 
 // Empty functions so tests don't need to be linked against commandline.cpp
 DefaultStandardStreamsCallback DEFAULT_STANDARD_STREAMS_CALLBACK(nullptr, nullptr);

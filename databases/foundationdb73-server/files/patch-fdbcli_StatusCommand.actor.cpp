--- fdbcli/StatusCommand.actor.cpp.orig	2025-07-02 21:14:39 UTC
+++ fdbcli/StatusCommand.actor.cpp
@@ -18,6 +18,8 @@
  * limitations under the License.
  */
 
+#include <ctime>
+
 #include "fdbcli/fdbcli.actor.h"
 #include "fmt/chrono.h"
 #include "fmt/core.h"
@@ -1142,7 +1144,7 @@ void printStatus(StatusObjectReader statusObj,
 								auto value = fmt::format("{}.{} dumped at {:%H:%M}. Total {} bytes.",
 								                         epoch,
 								                         seqNo,
-								                         fmt::localtime(dumpTs),
+								                         *std::localtime(&dumpTs),
 								                         sizeInBytes);
 								outputString += "\n  Last Manifest          - " + value;
 							} else {
@@ -1171,8 +1173,8 @@ void printStatus(StatusObjectReader statusObj,
 							std::string error = statusObjBlobRestore["blob_full_restore_error"].get_str();
 							int64_t startTs = statusObjBlobRestore["blob_full_restore_start_ts"].get_int64();
 							int64_t phaseStartTs = statusObjBlobRestore["blob_full_restore_phase_start_ts"].get_int64();
-							std::string tsShortStr = fmt::format("{:%H:%M}", fmt::localtime(phaseStartTs));
-							std::string tsLongStr = fmt::format("{:%m/%d/%y %H:%M:%S}", fmt::localtime(phaseStartTs));
+							std::string tsShortStr = fmt::format("{:%H:%M}", *std::localtime(&phaseStartTs));
+							std::string tsLongStr = fmt::format("{:%m/%d/%y %H:%M:%S}", *std::localtime(&phaseStartTs));
 
 							switch (statusObjBlobRestore["blob_full_restore_phase"].get_int()) {
 							case BlobRestorePhase::INIT:

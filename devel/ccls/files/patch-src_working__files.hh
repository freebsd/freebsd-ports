src/working_files.hh:89:8: error: no template named 'unordered_map' in namespace 'std'
  std::unordered_map<std::string, std::unique_ptr<WorkingFile>> files;
  ~~~~~^

https://github.com/MaskRay/ccls/pull/177

--- src/working_files.hh.orig	2018-12-25 15:28:45 UTC
+++ src/working_files.hh
@@ -21,6 +21,7 @@ limitations under the License.
 #include <mutex>
 #include <optional>
 #include <string>
+#include <unordered_map>
 
 namespace ccls {
 struct WorkingFile {

--- sql/server_component/mysql_json_encode_imp.cc.orig
+++ sql/server_component/mysql_json_encode_imp.cc
@@ -22,6 +22,7 @@
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */
 
 #include "mysql_json_encode_imp.h"
+#include <cstdio>
 #include "my_inttypes.h"
 #include "mysql/strings/m_ctype.h"
 
@@ -116,7 +117,7 @@
           /*
             Control characters must be escaped in JSON.
           */
-          int r = sprintf(reinterpret_cast<char *>(dst), "\\u%04x",
+          int r = std::sprintf(reinterpret_cast<char *>(dst), "\\u%04x",
                           static_cast<unsigned char>(wc));
           dst += r;
         } else if (wc < 0x80) {

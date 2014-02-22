--- ./zutils.h.orig	2014-01-30 14:46:32.000000000 -0200
+++ ./zutils.h	2014-02-22 09:12:24.000000000 -0300
@@ -15,6 +15,9 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <sys/types.h>
+#include <signal.h>
+
 int parse_format_type( const std::string & arg );
 
 int readblock( const int fd, uint8_t * const buf, const int size );

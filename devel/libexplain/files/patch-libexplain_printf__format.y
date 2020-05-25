--- libexplain/printf_format.y.orig	2013-12-08 01:47:33 UTC
+++ libexplain/printf_format.y
@@ -17,6 +17,7 @@
  * along with this program. If not, see <http://www.gnu.org/licenses/>.
  */
 
+%define api.prefix {printf_format_}
 %{
 
 #include <libexplain/ac/assert.h>

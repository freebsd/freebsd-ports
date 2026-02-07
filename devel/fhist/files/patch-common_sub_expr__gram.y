--- common/sub/expr_gram.y.orig	2012-07-13 04:47:15 UTC
+++ common/sub/expr_gram.y
@@ -16,6 +16,7 @@
  * along with this program. If not, see <http://www.gnu.org/licenses/>.
  */
 
+%define api.prefix {sub_expr_gram_}
 %{
 
 #include <common/ac/stdarg.h>

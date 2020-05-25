--- libexplain/parse_bits.y.orig	2013-12-08 01:47:33 UTC
+++ libexplain/parse_bits.y
@@ -17,6 +17,8 @@
  along with this program. If not, see <http://www.gnu.org/licenses/>.
  */
 
+%define api.prefix {parse_bits_}
+%define parse.error verbose
 %{
 
 #include <libexplain/ac/ctype.h>
@@ -38,7 +40,6 @@
 #include <libexplain/wrap_and_print.h>
 
 #define YYDEBUG 0
-#define YYERROR_VERBOSE 1
 
 #if YYDEBUG
 extern int yydebug;

--- libexplain/acl_grammar.y.orig	2013-12-08 01:47:33 UTC
+++ libexplain/acl_grammar.y
@@ -17,6 +17,8 @@
  * along with this program. If not, see <http://www.gnu.org/licenses/>.
  */
 
+%define api.prefix {acl_grammar_}
+%define parse.error verbose
 %{
 
 #include <libexplain/ac/ctype.h>
@@ -31,7 +33,6 @@
 #include <libexplain/acl_grammar.h>
 #include <libexplain/gcc_attributes.h>
 
-#define YYERROR_VERBOSE 1
 #define YYDEBUG 0
 
 /* is this forward enough? */

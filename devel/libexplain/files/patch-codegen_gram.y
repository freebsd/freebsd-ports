--- codegen/gram.y.orig	2013-12-08 01:47:33 UTC
+++ codegen/gram.y
@@ -17,6 +17,8 @@
  * with this program. If not, see <http://www.gnu.org/licenses/>.
  */
 
+%define api.prefix {gram_}
+%define parse.error verbose
 %{
 
 #include <libexplain/ac/stdio.h>
@@ -29,7 +31,6 @@
 #include <codegen/node.h>
 
 #define YYDEBUG 0
-#define YYERROR_VERBOSE 1
 
 %}
 

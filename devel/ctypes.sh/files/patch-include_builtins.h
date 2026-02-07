--- include/builtins.h.orig	2022-07-19 16:57:21 UTC
+++ include/builtins.h
@@ -18,7 +18,10 @@
    along with Bash.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#define ARRAY_VARS 1
+#ifdef HAVE_CONFIG_H
 #include "config.h"
+#endif
 
 #if defined (HAVE_UNISTD_H)
 #  ifdef _MINIX

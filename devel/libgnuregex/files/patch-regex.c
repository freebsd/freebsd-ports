--- regex.c.orig	2014-02-03 00:48:46 UTC
+++ regex.c
@@ -18,7 +18,7 @@
    <http://www.gnu.org/licenses/>.  */
 
 #ifndef _LIBC
-# include <config.h>
+# include "config.h"
 
 # if (__GNUC__ == 4 && 6 <= __GNUC_MINOR__) || 4 < __GNUC__
 #  pragma GCC diagnostic ignored "-Wsuggest-attribute=pure"
@@ -64,7 +64,7 @@
    #undefs RE_DUP_MAX and sets it to the right value.  */
 #include <limits.h>
 
-#include <regex.h>
+#include "regex.h"
 #include "regex_internal.h"
 
 #include "regex_internal.c"

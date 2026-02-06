--- lib/obstack.c.orig	2026-01-27 18:52:19 UTC
+++ lib/obstack.c
@@ -16,7 +16,10 @@
    License along with the GNU C Library; if not, see
    <https://www.gnu.org/licenses/>.  */
 
-
+#include <stdbool.h>
+#ifndef GNULIB_TEXT_DOMAIN
+#define GNULIB_TEXT_DOMAIN NULL
+#endif
 #ifdef _LIBC
 # include <obstack.h>
 # include <shlib-compat.h>

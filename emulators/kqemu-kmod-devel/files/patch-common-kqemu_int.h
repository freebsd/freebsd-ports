--- common/kqemu_int.h.orig
+++ common/kqemu_int.h
@@ -17,8 +17,16 @@
  * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 #ifndef __ASSEMBLY__
+#ifdef __FreeBSD__
+#include <sys/stddef.h>
+#include <machine/stdarg.h>
+#include <sys/cdefs.h>
+#include <machine/_types.h>
+typedef	__size_t	size_t;
+#else
 #include <stddef.h>
 #include <stdarg.h>
+#endif
 
 #ifndef NO_STD_TYPES
 

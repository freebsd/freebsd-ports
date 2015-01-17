--- conf.c.orig	2015-01-16 16:26:23.872241677 -0600
+++ conf.c	2015-01-16 16:27:00.595237894 -0600
@@ -15,6 +15,9 @@
  * this program; if not, write to the Free Software Foundation, Inc., 51
  * Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
 
 #include "conf.h"
 #include "ccache.h"
@@ -321,7 +324,11 @@ conf_create(void)
 	conf->read_only = false;
 	conf->read_only_direct = false;
 	conf->recache = false;
+#if __FreeBSD_version >= 1000024 || defined(CC_IS_CLANG)
+	conf->run_second_cpp = true;
+#else
 	conf->run_second_cpp = false;
+#endif
 	conf->sloppiness = 0;
 	conf->stats = true;
 	conf->temporary_dir = x_strdup("");

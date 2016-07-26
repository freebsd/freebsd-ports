--- raop_play/flac_stream.c.orig	2005-12-16 14:17:02 UTC
+++ raop_play/flac_stream.c
@@ -18,7 +18,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
  *****************************************************************************/
 #include <netinet/in.h>
-#include <asm/types.h>
+#include <sys/types.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <sys/stat.h>

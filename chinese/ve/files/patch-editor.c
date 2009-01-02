--- editor.c.orig	2008-12-21 22:42:24.000000000 +0800
+++ editor.c	2008-12-21 22:42:35.000000000 +0800
@@ -21,6 +21,7 @@
     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 
+#include <stdlib.h>
 #include "bbs.h"
 
 #define gtty(fd,data)  tcgetattr(fd,data)

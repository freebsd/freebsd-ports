
$FreeBSD$

--- src/syntax-highlight.c	2001/10/05 14:02:22	1.1
+++ src/syntax-highlight.c	2001/10/05 14:05:45
@@ -14,6 +14,7 @@
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#define _REGEX_H_
 #include <libgnomevfs/gnome-vfs-mime.h>
 
 #include "declarations.h"

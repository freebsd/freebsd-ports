--- drawpixmaps.c.orig	Sun Jul  4 18:50:44 1999
+++ drawpixmaps.c	Thu Mar 30 04:00:13 2000
@@ -14,7 +14,11 @@
 along with this program; see the file COPYING.  If not, write to
 the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 
+#ifndef __STDC__
 #include <malloc.h>
+#else
+#include <stdlib.h>
+#endif
 #include <stdio.h>
 #include <string.h>
 #include <X11/Xlib.h>

--- gd/gdhelpers.c.orig	Thu Jun  7 23:13:52 2001
+++ gd/gdhelpers.c	Thu Nov  8 17:10:18 2001
@@ -1,9 +1,9 @@
 #include "gd.h"
 #include "gdhelpers.h"
 #include <stdlib.h>
-#ifndef _OSD_POSIX      /* _OSD_POSIX defines *alloc() in stdlib.h */
+#ifndef __STDC__
 #include <malloc.h>
-#endif /*_OSD_POSIX*/
+#endif
 
 /* TBB: gd_strtok_r is not portable; provide an implementation */
 

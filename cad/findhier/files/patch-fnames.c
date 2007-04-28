--- fnames.c.orig	Sun Apr 29 00:51:29 2007
+++ fnames.c	Sun Apr 29 00:53:16 2007
@@ -6,15 +6,14 @@
  *
  */
 #include <stdio.h>
+#include <string.h>
 #ifndef DIRDEL
 #ifdef _UNIX_
 #define DIRDEL '/'
 #else
 #define DIRDEL '\\'
-#endif _UNIX_
-#endif DIRDEL
-
-int strlen();
+#endif /* _UNIX_ */
+#endif /* DIRDEL */
 
 char *basename(argv)
 char *argv;

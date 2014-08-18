--- src/bin/spiced.c.orig	2001-05-01 21:56:08.000000000 +0000
+++ src/bin/spiced.c
@@ -16,12 +16,11 @@ Author: 1985 Wayne A. Christopher, U. C.
 
 #include "spice.h"
 #include <stdio.h>
-#ifdef HAVE_STRINGS_H
-#include <strings.h>
-#else
 #include <string.h>
-#endif
 #include <errno.h>
+#include <unistd.h>
+#include <stdlib.h>
+#include <ctype.h>
 #include <sys/types.h>
 
 #ifdef HAVE_SOCKET
@@ -293,7 +292,7 @@ sigchild()
         (void) fclose(fp);
     } else
         nrunning--;
-    return;
+    return 0;
 }
 
 #else /* not HAVE_SOCKET */

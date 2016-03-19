--- src/bin/spiced.c.orig	2015-11-05 17:58:45 UTC
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

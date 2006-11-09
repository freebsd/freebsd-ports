--- allocate.c.orig	Fri May 19 16:53:10 1995
+++ allocate.c	Mon Dec 23 08:38:17 2002
@@ -4,7 +4,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include "ansi.h"
 #include "config.h"
 #include "allocate.h"

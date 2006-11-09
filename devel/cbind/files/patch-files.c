--- files.c.orig	Fri May 19 16:45:30 1995
+++ files.c	Mon Dec 23 08:38:17 2002
@@ -1,5 +1,6 @@
 #include "ansi.h"
 #include "hostinfo.h"
+#include "host.h"
 #include "config.h"
 
 #include <sys/types.h>
@@ -11,7 +12,7 @@
 #include <sys/mman.h>
 #else
 #include <unistd.h>
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #undef NULL

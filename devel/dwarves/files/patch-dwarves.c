--- dwarves.c.orig	2012-03-20 16:17:25 UTC
+++ dwarves.c
@@ -16,6 +16,8 @@
 #include <fcntl.h>
 #include <fnmatch.h>
 #include <libelf.h>
+/* For PATH_MAX */
+#include <limits.h>
 #include <search.h>
 #include <stdio.h>
 #include <stdlib.h>

--- dwarves.c.orig	2016-06-30 19:30:28 UTC
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

--- lib/src/clixon_handle.c.orig	2018-11-07 19:14:08 UTC
+++ lib/src/clixon_handle.c
@@ -43,7 +43,9 @@
 #include <errno.h>
 #include <string.h>
 #include <assert.h>
- 
+
+#include <sys/time.h>
+
 #include <cligen/cligen.h>
 
 /* clicon */

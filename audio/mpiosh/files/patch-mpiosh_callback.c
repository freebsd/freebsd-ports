--- mpiosh/callback.c.orig	2004-04-23 19:21:08 UTC
+++ mpiosh/callback.c
@@ -31,12 +31,15 @@
 #include <sys/stat.h>
 #include <time.h>
 #include <unistd.h>
+#include <limits.h>
 
 #include "mpiosh.h"
 #include "command.h"
 
 #include "libmpio/debug.h"
 
+#define NAME_MAX      PATH_MAX
+
 /* helper */
 BYTE
 mpiosh_ftype2ascii(BYTE ftype) {

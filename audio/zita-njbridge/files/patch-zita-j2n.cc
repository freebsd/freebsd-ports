--- zita-j2n.cc.orig	2021-07-02 16:35:56 UTC
+++ zita-j2n.cc
@@ -25,6 +25,7 @@
 #include <getopt.h>
 #include <math.h>
 #include <sys/mman.h>
+#include <unistd.h> // for usleep
 #include "jacktx.h"
 #include "nettx.h"
 #include "lfqueue.h"

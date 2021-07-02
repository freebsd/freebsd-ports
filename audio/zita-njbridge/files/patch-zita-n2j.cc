--- zita-n2j.cc.orig	2021-07-02 16:38:01 UTC
+++ zita-n2j.cc
@@ -25,6 +25,7 @@
 #include <signal.h>
 #include <getopt.h>
 #include <sys/mman.h>
+#include <unistd.h>
 #include "lfqueue.h"
 #include "netdata.h"
 #include "zsockets.h"

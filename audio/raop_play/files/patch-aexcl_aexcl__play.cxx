--- aexcl/aexcl_play.cxx.orig	2005-12-16 14:17:00 UTC
+++ aexcl/aexcl_play.cxx
@@ -23,6 +23,9 @@
 #include <signal.h>
 #include <sys/wait.h>
 #include <getopt.h>
+extern "C" {
+#include "getline.h"
+};
 #include "aexcl_gui.h"
 #include "aexcl_lib.h"
 #include "mDNS.h"

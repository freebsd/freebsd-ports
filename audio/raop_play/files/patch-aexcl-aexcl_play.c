--- aexcl/aexcl_play.cxx.orig	Fri Dec 16 23:17:00 2005
+++ aexcl/aexcl_play.cxx	Wed Jul  5 16:28:14 2006
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

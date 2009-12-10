--- sdk/codelite_indexer/utils.cpp.orig	2009-12-07 16:27:20.000000000 +0100
+++ sdk/codelite_indexer/utils.cpp	2009-12-07 16:26:55.000000000 +0100
@@ -11,6 +11,15 @@
 #    include <signal.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <fcntl.h>
+#include <paths.h>
+#include <kvm.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
+
 /**
  * helper string methods
  */

--- sdk/codelite_indexer/utils.cpp.orig	2010-08-02 08:43:19.000000000 +0200
+++ sdk/codelite_indexer/utils.cpp	2012-02-17 17:18:13.000000000 +0100
@@ -17,6 +17,15 @@
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

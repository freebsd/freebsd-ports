--- sdk/codelite_indexer/utils.cpp.orig	2009-09-15 08:00:45.000000000 +0200
+++ sdk/codelite_indexer/utils.cpp	2009-11-19 16:00:54.000000000 +0100
@@ -8,6 +8,16 @@
 # include <process.h>
 # include <Tlhelp32.h>
 #endif
+
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

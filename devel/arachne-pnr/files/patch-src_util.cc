--- src/util.cc.orig	2018-11-26 16:01:24 UTC
+++ src/util.cc
@@ -30,6 +30,7 @@
 #  include <mach-o/dyld.h>
 #  include <unistd.h>
 #elif defined(__FreeBSD__)
+#  include <sys/param.h>
 #  include <sys/sysctl.h>
 #  include <unistd.h>   // TODO 180528: remove this
 #else

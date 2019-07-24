--- hotspot/agent/src/os/bsd/ps_proc.c.orig	2019-07-21 20:24:28 UTC
+++ hotspot/agent/src/os/bsd/ps_proc.c
@@ -27,8 +27,8 @@
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
-#include <sys/sysctl.h>
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #include <sys/wait.h>
 #include <sys/ptrace.h>
 #include <sys/param.h>

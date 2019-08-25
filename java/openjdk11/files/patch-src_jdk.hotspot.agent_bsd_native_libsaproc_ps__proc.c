--- src/jdk.hotspot.agent/bsd/native/libsaproc/ps_proc.c
+++ src/jdk.hotspot.agent/bsd/native/libsaproc/ps_proc.c
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

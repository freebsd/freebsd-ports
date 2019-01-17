# expose getline in FreeBSD's stdio.h
#
--- src/intel/tools/error2aub.c.orig	2018-08-09 00:34:30 UTC
+++ src/intel/tools/error2aub.c
@@ -26,6 +26,9 @@
 #include <getopt.h>
 #include <inttypes.h>
 #include <signal.h>
+#if defined(__FreeBSD__) && __FreeBSD__ < 12
+#define _WITH_GETLINE
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

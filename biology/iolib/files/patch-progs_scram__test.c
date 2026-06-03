--- progs/scram_test.c.orig	2025-07-14 08:18:28 UTC
+++ progs/scram_test.c
@@ -48,6 +48,7 @@
 #include <assert.h>
 #include <ctype.h>
 #include <errno.h>
+#include <unistd.h>
 
 #if defined(__MINGW32__) || defined(__FreeBSD__) || defined(__APPLE__)
 #   include <getopt.h>

--- progs/scram_flagstat.c.orig	2025-07-14 08:18:28 UTC
+++ progs/scram_flagstat.c
@@ -44,6 +44,7 @@
 #include <assert.h>
 #include <ctype.h>
 #include <errno.h>
+#include <unistd.h>
 
 #if defined(__MINGW32__) || defined(__FreeBSD__) || defined(__APPLE__)
 #   include <getopt.h>

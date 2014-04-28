--- progs/scram_flagstat.c.orig
+++ progs/scram_flagstat.c
@@ -44,6 +44,7 @@
 #include <assert.h>
 #include <ctype.h>
 #include <errno.h>
+#include <unistd.h>
 
 #if defined(__MINGW32__)
 #   include <getopt.h>

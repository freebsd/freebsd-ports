--- ./progs/scram_test.c.orig	2014-05-31 14:25:16.000000000 -0300
+++ ./progs/scram_test.c	2014-05-31 14:25:27.000000000 -0300
@@ -44,6 +44,7 @@
 #include <assert.h>
 #include <ctype.h>
 #include <errno.h>
+#include <unistd.h>
 
 #if defined(__MINGW32__)
 #   include <getopt.h>

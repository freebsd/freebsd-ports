--- src/argp-local.h.orig	2003-11-25 23:51:41 UTC
+++ src/argp-local.h
@@ -12,6 +12,7 @@
 #include <getopt.h>
 #include <string.h>
 #include <iostream>
+#include <cstdlib>
 
 #define __need_error_t
 #include <errno.h>

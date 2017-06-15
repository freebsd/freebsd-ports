--- src/argp-local.h.orig	2003-11-25 23:51:41 UTC
+++ src/argp-local.h
@@ -12,6 +12,7 @@
 #include <getopt.h>
 #include <string.h>
 #include <iostream>
+#include <cstdlib>
 
 #define __need_error_t
 #include <errno.h>
@@ -65,7 +65,7 @@ const argp_option _argp_default_options[
 
 string _argp_progname(const char *arg)
 {
-char *p=strrchr(arg,'/');
+const char *p=strrchr(arg,'/');
 return p==NULL ? arg : p+1;
 }
 

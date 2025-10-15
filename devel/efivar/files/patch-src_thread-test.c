--- src/thread-test.c.orig	2024-01-31 20:08:46 UTC
+++ src/thread-test.c
@@ -6,7 +6,9 @@
 
 #include "fix_coverity.h"
 
-#include <alloca.h>
+#if defined(__linux__)
+#  include <alloca.h>
+#endif
 #include <efivar.h>
 #include <err.h>
 #include <errno.h>
@@ -125,7 +127,7 @@ usage(int ret)
 		"Help options:\n"
 		"  -?, --help                        Show this help message\n"
 		"      --usage                       Display brief usage message\n",
-		program_invocation_short_name);
+		getprogname());
 	exit(ret);
 }
 

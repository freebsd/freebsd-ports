--- src/ebusd/main.cpp.orig	2023-07-08 13:54:20 UTC
+++ src/ebusd/main.cpp
@@ -36,6 +36,9 @@
 #include "lib/utils/httpclient.h"
 #include "ebusd/scan.h"
 
+#ifdef __FreeBSD__
+extern char **environ;
+#endif
 
 /** the version string of the program. */
 const char *argp_program_version = "" PACKAGE_STRING "." REVISION "";

--- src/ebusd/main.cpp.orig	2022-07-12 12:56:35 UTC
+++ src/ebusd/main.cpp
@@ -34,6 +34,9 @@
 #include "lib/utils/log.h"
 #include "lib/utils/httpclient.h"
 
+#ifdef __FreeBSD__
+extern char **environ;
+#endif
 
 /** the version string of the program. */
 const char *argp_program_version = "" PACKAGE_STRING "." REVISION "";

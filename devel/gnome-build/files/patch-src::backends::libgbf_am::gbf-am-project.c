
$FreeBSD$

--- src/backends/libgbf_am/gbf-am-project.c	2001/07/24 11:44:39	1.1
+++ src/backends/libgbf_am/gbf-am-project.c	2001/07/24 11:46:14
@@ -33,6 +33,11 @@
 #include "../../lib/gnome-build.h"
 #include "gbf-am-project.h"
 
+#ifdef __FreeBSD__
+extern char **environ;
+#define __environ environ
+#endif
+
 #define SCRIPT_NAME "gbf-am-parse"
 #define BUILD_SCRIPT_NAME "gbf-am-build"
 

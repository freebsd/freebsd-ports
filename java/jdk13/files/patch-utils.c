$FreeBSD$

--- ../ext/plugin/oji-plugin/src/motif/common/utils.c	25 Aug 2001 17:48:42 -0000	1.2
+++ ../ext/plugin/oji-plugin/src/motif/common/utils.c	10 Jun 2002 20:27:38 -0000
@@ -10,6 +10,7 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #ifndef SVR4
+#include <sys/param.h>
 #include <sys/uio.h>
 #endif
 #include <fcntl.h>
@@ -17,6 +18,7 @@
 #include <locale.h>
 #include <errno.h>
 #include <strings.h>
+#include <string.h>
 #include <dlfcn.h>
 #include "plugin_defs.h"
 #include "pluginversion.h"

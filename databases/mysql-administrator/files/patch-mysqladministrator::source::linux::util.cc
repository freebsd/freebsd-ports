--- mysqladministrator/source/linux/util.cc.orig	Tue Feb 24 03:52:32 2004
+++ mysqladministrator/source/linux/util.cc	Tue Feb 24 03:53:35 2004
@@ -4,6 +4,7 @@
 #include "util.h"
 #include <glib.h>
 #include <stdarg.h>
+#include <unistd.h>
 
 #include <myx_library.h>
 

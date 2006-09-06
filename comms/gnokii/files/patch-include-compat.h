--- include/compat.h.orig	Tue Sep  5 14:13:49 2006
+++ include/compat.h	Tue Sep  5 14:14:37 2006
@@ -37,6 +37,8 @@
 #include "config.h"
 
 #include <stdlib.h>
+/* FreeBSD seems to require this one in various sources for "INT_MAX" */
+#include <limits.h>
 
 #ifdef WIN32
 #  include <windows.h>

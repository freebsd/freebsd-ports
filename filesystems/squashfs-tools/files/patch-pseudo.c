--- pseudo.c.orig	2014-05-10 04:54:13 UTC
+++ pseudo.c
@@ -34,6 +34,10 @@
 #include <sys/wait.h>
 #include <ctype.h>
 
+#ifdef __FreeBSD__
+#include <sys/stat.h>
+#endif
+
 #include "pseudo.h"
 #include "error.h"
 #include "progressbar.h"

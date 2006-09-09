--- hfkernel/fsk/amtor.c.orig	Sun Jul 30 01:38:53 2006
+++ hfkernel/fsk/amtor.c	Sun Jul 30 01:39:10 2006
@@ -32,6 +32,7 @@
 #include <assert.h>
 #include <syslog.h>
 #include <string.h>
+#include <sys/types.h>
 
 #include "fskl1.h"
 #include "fskutil.h"

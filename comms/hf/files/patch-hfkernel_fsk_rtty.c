--- hfkernel/fsk/rtty.c.orig	Sun Jul 30 01:41:43 2006
+++ hfkernel/fsk/rtty.c	Sun Jul 30 01:43:29 2006
@@ -33,6 +33,7 @@
 #include <syslog.h>
 #include <string.h>
 #include <stdio.h>
+#include <sys/types.h>
 
 #include "fskl1.h"
 #include "fskutil.h"

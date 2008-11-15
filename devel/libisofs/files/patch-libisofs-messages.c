--- libisofs/messages.c.orig 2008-10-06 02:44:52.000000000 -0400
+++ libisofs/messages.c  2008-11-06 16:48:40.000000000 -0500
@@ -9,6 +9,7 @@
 #include <string.h>
 #include <stdio.h>
 #include <stdarg.h>
+#include <sys/types.h>
 
 #include "libiso_msgs.h"
 #include "libisofs.h"

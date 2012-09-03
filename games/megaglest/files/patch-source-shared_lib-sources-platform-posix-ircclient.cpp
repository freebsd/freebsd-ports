--- source/shared_lib/sources/platform/posix/ircclient.cpp	2012-01-23 14:36:15.000000000 -0600
+++ source/shared_lib/sources/platform/posix/ircclient.cpp.new	2012-06-24 09:51:37.000000000 -0500
@@ -14,11 +14,7 @@
 #include "util.h"
 #include "platform_common.h"
 #include "libircclient.h"
-
-// upstream moved some defines into new headers as of 1.6
-#ifndef LIBIRCCLIENT_PRE1_6
 #include "libirc_rfcnumeric.h"
-#endif
 
 #include <stdio.h>
 #include <stdarg.h>

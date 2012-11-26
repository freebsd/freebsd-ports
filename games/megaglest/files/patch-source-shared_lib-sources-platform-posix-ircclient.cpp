--- source/shared_lib/sources/platform/posix/ircclient.cpp	2012-11-10 03:22:28.000000000 -0600
+++ source/shared_lib/sources/platform/posix/ircclient.cpp.new	2012-11-20 11:51:10.000000000 -0600
@@ -14,11 +14,7 @@
 #include "util.h"
 #include "platform_common.h"
 #include <libircclient.h>
-
-// upstream moved some defines into new headers as of 1.6
-#ifndef LIBIRCCLIENT_PRE1_6
 #include <libirc_rfcnumeric.h>
-#endif
 
 #include <stdio.h>
 #include <stdarg.h>

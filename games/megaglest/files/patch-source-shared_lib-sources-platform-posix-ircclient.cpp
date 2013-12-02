--- source/shared_lib/sources/platform/posix/ircclient.cpp.orig	2013-11-22 15:51:23.000000000 -0600
+++ source/shared_lib/sources/platform/posix/ircclient.cpp	2013-11-22 15:51:42.000000000 -0600
@@ -19,10 +19,7 @@
 #if !defined(DISABLE_IRCCLIENT)
 
 #include <libircclient.h>
-// upstream moved some defines into new headers as of 1.6
-#ifndef LIBIRCCLIENT_PRE1_6
 #include <libirc_rfcnumeric.h>
-#endif
 
 #endif
 

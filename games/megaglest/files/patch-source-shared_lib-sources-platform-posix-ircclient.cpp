--- source/shared_lib/sources/platform/posix/ircclient.cpp.orig	2016-04-02 12:36:57 UTC
+++ source/shared_lib/sources/platform/posix/ircclient.cpp
@@ -19,10 +19,7 @@
 #if !defined(DISABLE_IRCCLIENT)
 
 #include <libircclient.h>
-// upstream moved some defines into new headers as of 1.6
-#ifndef LIBIRCCLIENT_PRE1_6
 #include <libirc_rfcnumeric.h>
-#endif
 
 #endif
 

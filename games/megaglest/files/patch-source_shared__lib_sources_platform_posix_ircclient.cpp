--- source/shared_lib/sources/platform/posix/ircclient.cpp.orig	2017-03-12 11:21:46 UTC
+++ source/shared_lib/sources/platform/posix/ircclient.cpp
@@ -20,9 +20,7 @@
 
 #include <libircclient.h>
 // upstream moved some defines into new headers as of 1.6
-#ifndef LIBIRCCLIENT_PRE1_6
 #include <libirc_rfcnumeric.h>
-#endif
 
 #endif
 

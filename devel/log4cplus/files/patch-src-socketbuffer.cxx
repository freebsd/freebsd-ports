--- src/socketbuffer.cxx.orig	Fri Nov 21 22:23:29 2003
+++ src/socketbuffer.cxx	Thu Dec  9 15:49:28 2004
@@ -29,6 +29,7 @@
 
 #include <log4cplus/helpers/socketbuffer.h>
 #include <log4cplus/helpers/loglog.h>
+#include <arpa/inet.h>
 
 #if !defined(_WIN32)
 #  include <netdb.h>

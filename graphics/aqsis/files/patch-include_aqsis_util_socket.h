--- include/aqsis/util/socket.h.orig	2012-08-24 12:26:50 UTC
+++ include/aqsis/util/socket.h
@@ -32,7 +32,9 @@
 
 #include <sstream>
 
+#ifndef Q_MOC_RUN
 #include <boost/utility.hpp>
+#endif
 
 #ifdef AQSIS_SYSTEM_WIN32
 #	include <winsock2.h>

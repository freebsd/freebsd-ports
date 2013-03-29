--- src/xmlrpcpp/XmlRpcDispatch.cpp.orig	2013-03-28 09:09:49.000000000 -0500
+++ src/xmlrpcpp/XmlRpcDispatch.cpp	2013-03-28 09:10:13.000000000 -0500
@@ -10,7 +10,9 @@
 
 #include <errno.h>
 #include <math.h>
+#ifdef USE_FTIME
 #include <sys/timeb.h>
+#endif
 
 #if defined(_WINDOWS)
 # include <winsock2.h>

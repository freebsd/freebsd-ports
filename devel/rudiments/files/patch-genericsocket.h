--- include/rudiments/genericsocket.h.bak	Mon Apr 15 06:21:25 2002
+++ include/rudiments/genericsocket.h	Sun Feb 29 01:55:13 2004
@@ -4,12 +4,14 @@
 #ifndef GENERICSOCKET_H
 #define GENERICSOCKET_H
 
-#include <strstream.h>
+#include <strstream>
 
 #include <sys/types.h>
 #include <sys/un.h>
 #include <netinet/in.h>
 #include <netdb.h>
+
+using namespace std;
 
 // The client class allows you to write programs that can talk to other
 // programs over TCP connections.

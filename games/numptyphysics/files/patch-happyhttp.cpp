--- happyhttp.cpp.orig	2008-08-28 14:08:27.000000000 +0400
+++ happyhttp.cpp	2013-09-17 21:10:39.685520377 +0400
@@ -30,6 +30,7 @@
 #ifndef WIN32
 //	#include <sys/types.h>
 	#include <sys/socket.h>
+	#include <sys/select.h>
 	#include <netinet/in.h>
 	#include <arpa/inet.h>
 	#include <netdb.h>	// for gethostbyname()
@@ -45,11 +46,14 @@
 #include <cstring>
 #include <cstdarg>
 #include <assert.h>
+#include <unistd.h>
 
 #include <string>
 #include <vector>
 #include <string>
 #include <algorithm>
+#include <cstdlib>
+#include <ctime>
 
 
 

$FreeBSD$

--- io.cpp.orig	Sat Oct 19 11:51:21 2002
+++ io.cpp	Thu Nov  7 15:29:13 2002
@@ -36,7 +36,7 @@
 #include "util.h"
 #include <stdio.h>
 #ifdef HAVE_SENDFILE
-#include <sys/sendfile.h>
+#include <sys/socket.h>
 #endif
 
 using namespace std;
@@ -162,7 +163,7 @@ size_t write_file(int fd, const string& 
 			throw TransportException(__FILE__, __LINE__, tmp);
 		}
 #ifdef HAVE_SENDFILE
-		int rc = sendfile(fd, in, 0, filesize);
+		int rc = sendfile(fd, in, 0, filesize, 0, 0, 0);
 		if (rc<0) {
 			perror("sendfile");
 			assert(0);

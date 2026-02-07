--- src/remote.cpp.old	Thu May 20 19:24:47 2004
+++ src/remote.cpp	Thu Aug 19 18:16:57 2004
@@ -22,6 +22,7 @@
 
 #ifndef WIN32
 # include <unistd.h>
+# undef _BSD_SOCKLEN_T_
 # include <sys/socket.h>
 # include <netdb.h>
 # ifdef HAVE_NETINET_IN_H

--- src/threads.cc.orig	Sun Jul 14 08:53:50 2002
+++ src/threads.cc	Tue Jul 16 00:01:18 2002
@@ -39,6 +39,7 @@
 #include <errno.h>
 #include <algorithm>
 #include <fstream.h> /* Portability fix: used to be <fstream> */
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <netdb.h>


$FreeBSD$

--- cddbslave/socks4.c	2001/12/06 08:10:34	1.1
+++ cddbslave/socks4.c	2001/12/06 08:11:08
@@ -33,12 +33,12 @@
 #include <errno.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/time.h>
 #include <netinet/in.h>
 #include <unistd.h>
 #include <pwd.h>
-#include <sys/types.h>
 #include <sys/select.h>
 #include <dlfcn.h>
 

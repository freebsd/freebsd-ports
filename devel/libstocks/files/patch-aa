--- lib/http.c	Tue Sep  5 10:42:34 2000
+++ lib/http.c	Tue Jan  8 00:09:06 2002
@@ -21,5 +21,7 @@
 #define __HTTP_C__
 
 #ifdef __UNIX__
+#include <sys/types.h>
+
 #include <sys/socket.h>
 #include <netinet/in.h>
@@ -32,5 +34,4 @@
 #endif
 
-#include <sys/types.h>
 #include <ctype.h>
 #include <string.h>

--- room_new/server_code.c.old	Sat Feb  9 15:06:52 2002
+++ room_new/server_code.c	Sat Feb  9 15:07:06 2002
@@ -8,6 +8,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>

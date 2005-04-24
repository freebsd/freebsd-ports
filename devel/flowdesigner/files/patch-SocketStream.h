--- data-flow/include/SocketStream.h.orig
+++ data-flow/include/SocketStream.h
@@ -5,13 +5,13 @@
 //Dominic Letourneau 03/10/2001
 
 #include <stddef.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include "Object.h"
 #include "net_types.h"
 #include <iostream>
 #include <stdio.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 

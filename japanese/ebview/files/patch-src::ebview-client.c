--- src/ebview-client.c.orig	Sat Nov 16 15:33:47 2002
+++ src/ebview-client.c	Sat Nov 30 09:49:47 2002
@@ -1,8 +1,8 @@
 #include <stdio.h>
-#include <sys/socket.h>
+#include <unistd.h>
 #include <sys/un.h>
 #include <sys/types.h>
-#include <unistd.h>
+#include <sys/socket.h>
 
 #include "../config.h"
 

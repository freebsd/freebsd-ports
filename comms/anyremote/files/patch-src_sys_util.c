--- src/sys_util.c	2013-07-10 14:49:42.461289772 +0200
+++ src/sys_util.c	2013-07-10 14:49:02.000000000 +0200
@@ -24,13 +24,13 @@
 #include <dirent.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <net/if.h>
 #include <netinet/in.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
+#include <net/if.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/wait.h>

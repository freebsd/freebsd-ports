Index: dlls/kernel/sync.c
===================================================================
RCS file: /home/wine/wine/dlls/kernel/sync.c,v
retrieving revision 1.76
diff -u -3 -p -r1.76 sync.c
--- dlls/kernel/sync.c	18 Apr 2005 14:57:04 -0000	1.76
+++ dlls/kernel/sync.c	19 Apr 2005 19:53:50 -0000
@@ -38,6 +38,7 @@
 #ifdef HAVE_SYS_SOCKET_H
 #include <sys/socket.h>
 #endif
+#include <limits.h>
 #include <stdarg.h>
 #include <stdio.h>
 

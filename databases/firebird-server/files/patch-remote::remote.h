--- remote/remote.h	2002/10/21 13:03:48	1.1
+++ remote/remote.h	2002/10/21 13:04:15
@@ -47,6 +47,7 @@
 #endif
 #ifndef WINDOWS_ONLY
 #include <fcntl.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
 #endif /* WINDOWS_ONLY */

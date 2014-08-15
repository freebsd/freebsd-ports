--- service/ConnectionListener_unix.cpp
+++ service/ConnectionListener_unix.cpp
@@ -17,7 +17,7 @@
 #include "service/ConnectionListener.h"
 #include "common/Socket.h"
 
-#if defined(_MACOSX) && !defined(SOCK_CLOEXEC)
+#if (defined(_MACOSX) || defined (__FreeBSD__)) && !defined(SOCK_CLOEXEC)
 #define SOCK_CLOEXEC 0
 #endif
 

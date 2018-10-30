--- service/ConnectionListener_unix.cpp.orig	2014-03-31 10:30:09 UTC
+++ service/ConnectionListener_unix.cpp
@@ -13,11 +13,12 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <string>
+#include <cstring>
 
 #include "service/ConnectionListener.h"
 #include "common/Socket.h"
 
-#if defined(_MACOSX) && !defined(SOCK_CLOEXEC)
+#if (defined(_MACOSX) || defined (__FreeBSD__)) && !defined(SOCK_CLOEXEC)
 #define SOCK_CLOEXEC 0
 #endif
 

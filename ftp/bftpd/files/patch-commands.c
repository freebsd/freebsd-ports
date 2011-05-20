--- commands.c.orig	2011-05-20 14:39:41.000000000 -0300
+++ commands.c	2011-05-20 14:40:45.000000000 -0300
@@ -18,9 +18,6 @@
 #ifdef HAVE_SYS_SOCKET_H
 #include <sys/socket.h>
 #endif
-#ifdef HAVE_ASM_SOCKET_H
-#include <asm/socket.h>
-#endif
 #ifdef HAVE_NETINET_IN_H
 #include <netinet/in.h>
 #endif
@@ -35,12 +32,8 @@
 #endif
 #include <fcntl.h>
 #include <string.h>
-#ifdef HAVE_WAIT_H
-# include <wait.h>
-#else
-# ifdef HAVE_SYS_WAIT_H
-#  include <sys/wait.h>
-# endif
+#ifdef HAVE_SYS_WAIT_H
+#include <sys/wait.h>
 #endif
 
 #include "mystring.h"

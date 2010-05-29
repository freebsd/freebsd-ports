--- src/ipc/unix_ipc.cc.org	2010-05-29 11:06:11.125610530 +0900
+++ src/ipc/unix_ipc.cc	2010-05-29 11:33:18.938743764 +0900
@@ -41,7 +41,7 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/un.h>
-#ifdef OS_MACOSX
+#ifdef __FreeBSD__
 #include <sys/ucred.h>
 #endif
 #include <sys/wait.h>
@@ -124,7 +124,7 @@
 bool IsPeerValid(int socket, pid_t *pid) {
   *pid = 0;
 
-#ifdef OS_MACOSX
+#ifdef __FreeBSD__
   // If the OS is MAC, we should validate the peer by using LOCAL_PEERCRED.
   struct xucred peer_cred;
   socklen_t peer_cred_len = sizeof(struct xucred);
@@ -146,6 +146,7 @@
   *pid = 0;
 #endif
 
+/*
 #ifdef OS_LINUX
   // On ARM Linux, we do nothing and just return true since the platform (at
   // least the qemu emulator) doesn't support the getsockopt(sock, SOL_SOCKET,
@@ -171,7 +172,7 @@
   *pid = peer_cred.pid;
 #endif  // __arm__
 #endif
-
+*/
   return true;
 }
 

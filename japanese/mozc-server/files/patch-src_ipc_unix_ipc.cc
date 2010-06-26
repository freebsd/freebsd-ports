--- ipc/unix_ipc.cc.org	2010-06-17 15:59:08.061722403 +0900
+++ ipc/unix_ipc.cc	2010-06-26 14:57:03.788901462 +0900
@@ -41,7 +41,7 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/un.h>
-#ifdef OS_MACOSX
+#if defined(__FreeBSD__) || defined(OS_MACOSX)
 #include <sys/ucred.h>
 #endif
 #include <sys/wait.h>
@@ -124,7 +124,7 @@
 bool IsPeerValid(int socket, pid_t *pid) {
   *pid = 0;
 
-#ifdef OS_MACOSX
+#if defined(__FreeBSD__) || defined(OS_MACOSX)
   // If the OS is MAC, we should validate the peer by using LOCAL_PEERCRED.
   struct xucred peer_cred;
   socklen_t peer_cred_len = sizeof(struct xucred);
@@ -146,7 +146,7 @@
   *pid = 0;
 #endif
 
-#ifdef OS_LINUX
+#if !defined(__FreeBSD__) && defined(OS_LINUX)
   // On ARM Linux, we do nothing and just return true since the platform (at
   // least the qemu emulator) doesn't support the getsockopt(sock, SOL_SOCKET,
   // SO_PEERCRED) system call.

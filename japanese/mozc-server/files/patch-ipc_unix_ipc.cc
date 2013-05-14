--- ipc/unix_ipc.cc.orig	2013-03-29 13:33:26.000000000 +0900
+++ ipc/unix_ipc.cc	2013-04-27 15:23:08.000000000 +0900
@@ -41,6 +41,9 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/un.h>
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
+#include <sys/ucred.h>
+#endif
 #include <sys/wait.h>
 #include <unistd.h>
 
@@ -123,6 +126,29 @@
 bool IsPeerValid(int socket, pid_t *pid) {
   *pid = 0;
 
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
+  // If the OS is MAC, we should validate the peer by using LOCAL_PEERCRED.
+  struct xucred peer_cred;
+  socklen_t peer_cred_len = sizeof(struct xucred);
+  if (::getsockopt(socket, 0, LOCAL_PEERCRED,
+                   &peer_cred, &peer_cred_len) < 0) {
+    LOG(ERROR) << "cannot get peer credential.  NOT a Unix socket?";
+    return false;
+  }
+  if (peer_cred.cr_version != XUCRED_VERSION) {
+    LOG(WARNING) << "credential version mismatch.";
+    return false;
+  }
+  if (peer_cred.cr_uid != ::geteuid()) {
+    LOG(WARNING) << "uid mismatch." << peer_cred.cr_uid << "!=" << ::geteuid();
+    return false;
+  }
+
+  // MacOS doesn't have cr_pid;
+  *pid = 0;
+#endif
+
+#if defined(OS_LINUX) && !defined(OS_FREEBSD)
   // On ARM Linux, we do nothing and just return true since the platform
   // sometimes doesn't support the getsockopt(sock, SOL_SOCKET, SO_PEERCRED)
   // system call.
@@ -144,6 +170,7 @@
 
   *pid = peer_cred.pid;
 #endif  // __arm__
+#endif
 
   return true;
 }
@@ -278,7 +305,12 @@
     address.sun_family = AF_UNIX;
     ::memcpy(address.sun_path, server_address.data(), server_address_length);
     address.sun_path[server_address_length] = '\0';
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
+    address.sun_len = SUN_LEN(&address);
+    const size_t sun_len = sizeof(address);
+#else
     const size_t sun_len = sizeof(address.sun_family) + server_address_length;
+#endif
     pid_t pid = 0;
     if (::connect(socket_,
                   reinterpret_cast<const sockaddr*>(&address),
@@ -398,16 +430,21 @@
                SO_REUSEADDR,
                reinterpret_cast<char *>(&on),
                sizeof(on));
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
+  addr.sun_len = SUN_LEN(&addr);
+  const size_t sun_len = sizeof(addr);
+#else
   const size_t sun_len = sizeof(addr.sun_family) + server_address_.size();
-  if (!IsAbstractSocket(server_address_)) {
-    // Linux does not use files for IPC.
-    ::chmod(server_address_.c_str(), 0600);
-  }
+#endif
   if (::bind(socket_, reinterpret_cast<sockaddr *>(&addr), sun_len) != 0) {
     // The UNIX domain socket file (server_address_) already exists?
     LOG(FATAL) << "bind() failed: " << strerror(errno);
     return;
   }
+  if (!IsAbstractSocket(server_address_)) {
+    // Linux does not use files for IPC.
+    ::chmod(server_address_.c_str(), 0600);
+  }
 
   if (::listen(socket_, num_connections) < 0) {
     LOG(FATAL) << "listen() failed: " << strerror(errno);

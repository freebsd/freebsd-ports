--- ipc/unix_ipc.cc.org	2010-11-06 10:51:14.204190823 +0900
+++ ipc/unix_ipc.cc	2010-11-06 10:54:18.096187153 +0900
@@ -41,7 +41,7 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/un.h>
-#ifdef OS_MACOSX
+#if defined(OS_MACOSX) || defined(__FreeBSD__)
 #include <sys/ucred.h>
 #endif
 #include <sys/wait.h>
@@ -124,7 +124,7 @@
 bool IsPeerValid(int socket, pid_t *pid) {
   *pid = 0;
 
-#ifdef OS_MACOSX
+#if defined(OS_MACOSX) || defined(__FreeBSD__)
   // If the OS is MAC, we should validate the peer by using LOCAL_PEERCRED.
   struct xucred peer_cred;
   socklen_t peer_cred_len = sizeof(struct xucred);
@@ -146,7 +146,7 @@
   *pid = 0;
 #endif
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && !defined(__FreeBSD__)
   struct ucred peer_cred;
   int peer_cred_len = sizeof(peer_cred);
   if (getsockopt(socket, SOL_SOCKET, SO_PEERCRED,
@@ -303,7 +303,7 @@
     address.sun_family = AF_UNIX;
     ::memcpy(address.sun_path, server_address.data(), server_address_length);
     address.sun_path[server_address_length] = '\0';
-#ifdef OS_MACOSX
+#if defined(OS_MACOSX) || defined(__FreeBSD__)
     address.sun_len = SUN_LEN(&address);
     const size_t sun_len = sizeof(address);
 #else
@@ -423,21 +423,21 @@
                SO_REUSEADDR,
                reinterpret_cast<char *>(&on),
                sizeof(on));
-#ifdef OS_MACOSX
+#if defined(OS_MACOSX) || defined(__FreeBSD__)
   addr.sun_len = SUN_LEN(&addr);
   const size_t sun_len = sizeof(addr);
 #else
   const size_t sun_len = sizeof(addr.sun_family) + server_address_.size();
 #endif
-  if (!IsAbstractSocket(server_address_)) {
-    // Linux does not use files for IPC.
-    ::chmod(server_address_.c_str(), 0600);
-  }
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

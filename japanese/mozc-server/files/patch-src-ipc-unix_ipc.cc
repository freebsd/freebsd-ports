--- src/ipc/unix_ipc.cc.orig	2026-10-16 12:33:33 UTC
+++ src/ipc/unix_ipc.cc
@@ -28,13 +28,16 @@
 // OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 // __linux__ only. Note that __ANDROID__/__wasm__ don't reach here.
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 
 #include <fcntl.h>
 #include <sys/select.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/time.h>
+#if defined(__FreeBSD__)
+#include <sys/ucred.h>
+#endif // __FreeBSD__
 #include <sys/un.h>
 #include <unistd.h>
 
@@ -55,9 +58,13 @@
 #include "ipc/ipc.h"
 #include "ipc/ipc_path_manager.h"
 
+#if defined(__FreeBSD__)
+#define UNIX_PATH_MAX sizeof(((struct sockaddr_un *)nullptr)->sun_path)
+#else	// __FreeBSD__
 #ifndef UNIX_PATH_MAX
 #define UNIX_PATH_MAX 108
 #endif  // UNIX_PATH_MAX
+#endif  // __FreeBSD__
 
 namespace mozc {
 namespace {
@@ -121,21 +128,45 @@ bool IsPeerValid(int socket, pid_t *pid) {
 bool IsPeerValid(int socket, pid_t *pid) {
   *pid = 0;
 
-  struct ucred peer_cred;
-  int peer_cred_len = sizeof(peer_cred);
-  if (getsockopt(socket, SOL_SOCKET, SO_PEERCRED, &peer_cred,
-                 reinterpret_cast<socklen_t *>(&peer_cred_len)) < 0) {
-    LOG(ERROR) << "cannot get peer credential. Not a Unix socket?";
+#if defined(__FreeBSD__)
+  struct xucred peer_cred = {};
+  socklen_t peer_cred_len = sizeof(peer_cred);
+  if (getsockopt(socket, SOL_LOCAL, LOCAL_PEERCRED,
+                 &peer_cred, &peer_cred_len) < 0) {
+    LOG(ERROR) << "cannot get peer credential: " << strerror(errno);
     return false;
   }
+  if (peer_cred_len != sizeof(peer_cred) ||
+      peer_cred.cr_version != XUCRED_VERSION) {
+    LOG(ERROR) << "invalid peer credential";
+    return false;
+  }
+  const uid_t peer_uid = peer_cred.cr_uid;
+  const pid_t peer_pid = peer_cred.cr_pid;
+#else
+  struct ucred peer_cred = {};
+  socklen_t peer_cred_len = sizeof(peer_cred);
+  if (getsockopt(socket, SOL_SOCKET, SO_PEERCRED,
+                 &peer_cred, &peer_cred_len) < 0) {
+    LOG(ERROR) << "cannot get peer credential: " << strerror(errno);
+    return false;
+  }
+  const uid_t peer_uid = peer_cred.uid;
+  const pid_t peer_pid = peer_cred.pid;
+#endif
 
-  if (peer_cred.uid != ::geteuid()) {
-    LOG(WARNING) << "uid mismatch." << peer_cred.uid << "!=" << ::geteuid();
+  if (peer_uid != ::geteuid()) {
+    LOG(WARNING) << "uid mismatch." << peer_uid << "!=" << ::geteuid();
     return false;
   }
 
-  *pid = peer_cred.pid;
+  if (peer_pid <= 0) {
+    LOG(ERROR) << "invalid peer pid: " << peer_pid;
+    return false;
+  }
 
+  *pid = peer_pid;
+
   return true;
 }
 
@@ -250,9 +281,6 @@ void IPCClient::Init(absl::string_view name,
       continue;
     }
     sockaddr_un address = {};
-    const size_t server_address_length =
-        (server_address.size() >= UNIX_PATH_MAX) ? UNIX_PATH_MAX - 1
-                                                 : server_address.size();
     if (server_address.size() >= UNIX_PATH_MAX) {
       LOG(WARNING) << "too long path: " << server_address;
     }
@@ -265,7 +293,15 @@ void IPCClient::Init(absl::string_view name,
     address.sun_family = AF_UNIX;
     absl::SNPrintF(address.sun_path, sizeof(address.sun_path), "%s",
                    server_address);
+#if defined(__FreeBSD__)
+    address.sun_len = SUN_LEN(&address);
+    const socklen_t sun_len = address.sun_len;
+#else	// __FreeBSD__
+    const size_t server_address_length =
+        (server_address.size() >= UNIX_PATH_MAX) ? UNIX_PATH_MAX - 1
+                                                 : server_address.size();
     const size_t sun_len = sizeof(address.sun_family) + server_address_length;
+#endif	// __FreeBSD__
     pid_t pid = 0;
     if (::connect(socket_, reinterpret_cast<const sockaddr *>(&address),
                   sun_len) != 0 ||
@@ -381,10 +417,22 @@ IPCServer::IPCServer(absl::string_view name, int32_t n
   int on = 1;
   ::setsockopt(socket_, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<char *>(&on),
                sizeof(on));
+#if defined(__FreeBSD__)
+  addr.sun_len = SUN_LEN(&addr);
+  const socklen_t sun_len = addr.sun_len;
+#else	// __FreeBSD__
   const size_t sun_len = sizeof(addr.sun_family) + server_address_.size();
+#endif	// __FreeBSD__
   if (is_file_socket) {
     // Linux does not use files for IPC.
+#if defined(__FreeBSD__)
+    if (::fchmod(socket_, 0600) != 0) {
+      LOG(ERROR) << "fchmod() failed: " << strerror(errno);
+      return;
+    }
+#else	// __FreeBSD__
     ::chmod(server_address_.c_str(), 0600);
+#endif	// __FreeBSD__
   }
   if (::bind(socket_, reinterpret_cast<sockaddr *>(&addr), sun_len) != 0) {
     // The UNIX domain socket file (server_address_) already exists?
@@ -434,6 +482,7 @@ void IPCServer::Loop() {
       return;
     }
     if (!IsPeerValid(new_sock, &pid)) {
+      ::close(new_sock);
       continue;
     }
 
@@ -481,4 +530,4 @@ void IPCServer::Terminate() {
 
 }  // namespace mozc
 
-#endif  // __linux__
+#endif  // __linux__ || __FreeBSD__

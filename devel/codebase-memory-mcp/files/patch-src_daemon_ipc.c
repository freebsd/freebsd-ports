--- src/daemon/ipc.c.orig	2026-08-15 21:31:53 UTC
+++ src/daemon/ipc.c
@@ -313,6 +313,9 @@ int cbm_daemon_ipc_wait_pending(const cbm_ipc_pending_
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/un.h>
+#if defined(__FreeBSD__)
+#include <sys/ucred.h> // struct xucred (LOCAL_PEERCRED peer pid)
+#endif
 #include <time.h>
 #include <unistd.h>
 
@@ -3060,6 +3063,19 @@ uint64_t cbm_daemon_ipc_connection_peer_pid(const cbm_
         return 0;
     }
     return (uint64_t)peer_pid;
+#elif defined(__FreeBSD__) && defined(LOCAL_PEERCRED)
+    /* FreeBSD has neither SO_PEERCRED nor LOCAL_PEERPID; LOCAL_PEERCRED returns
+     * a struct xucred whose cr_pid (FreeBSD 13+) is the connecting peer's pid.
+     * cr_pid is only meaningful when the version matches and the socket is a
+     * connected stream, both true for our accepted control connection. */
+    struct xucred credentials;
+    socklen_t length = sizeof(credentials);
+    if (getsockopt(connection->fd, SOL_LOCAL, LOCAL_PEERCRED, &credentials, &length) != 0 ||
+        length != sizeof(credentials) || credentials.cr_version != XUCRED_VERSION ||
+        credentials.cr_uid != geteuid() || credentials.cr_pid <= 0) {
+        return 0;
+    }
+    return (uint64_t)credentials.cr_pid;
 #else
     return 0;
 #endif

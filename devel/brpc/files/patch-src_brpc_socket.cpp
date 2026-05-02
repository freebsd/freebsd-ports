--- src/brpc/socket.cpp.orig	2026-02-23 02:11:29 UTC
+++ src/brpc/socket.cpp
@@ -52,7 +52,7 @@
 #include "brpc/details/health_check.h"
 #include "brpc/rdma/rdma_endpoint.h"
 #include "brpc/rdma/rdma_helper.h"
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 #include <sys/event.h>
 #endif
 
@@ -677,6 +677,30 @@ void Socket::SetSocketOptions(int fd) {
             PLOG(ERROR) << "Fail to set keepcnt of fd=" << fd;
         }
     }
+#elif defined(OS_FREEBSD)
+    if (_keepalive_options->keepalive_idle_s > 0) {
+        if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE,
+                       &_keepalive_options->keepalive_idle_s,
+                       sizeof(_keepalive_options->keepalive_idle_s)) != 0) {
+            PLOG(ERROR) << "Fail to set keepidle of fd=" << fd;
+        }
+    }
+
+    if (_keepalive_options->keepalive_interval_s > 0) {
+        if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL,
+                       &_keepalive_options->keepalive_interval_s,
+                       sizeof(_keepalive_options->keepalive_interval_s)) != 0) {
+            PLOG(ERROR) << "Fail to set keepintvl of fd=" << fd;
+        }
+    }
+
+    if (_keepalive_options->keepalive_count > 0) {
+        if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPCNT,
+                       &_keepalive_options->keepalive_count,
+                       sizeof(_keepalive_options->keepalive_count)) != 0) {
+            PLOG(ERROR) << "Fail to set keepcnt of fd=" << fd;
+        }
+    }
 #elif defined(OS_MACOSX)
     if (_keepalive_options->keepalive_idle_s > 0) {
         if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPALIVE,
@@ -2068,7 +2092,7 @@ int Socket::SSLHandshake(int fd, bool server_mode) {
         case SSL_ERROR_WANT_READ:
 #if defined(OS_LINUX)
             if (bthread_fd_wait(fd, EPOLLIN) != 0) {
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
             if (bthread_fd_wait(fd, EVFILT_READ) != 0) {
 #endif
                 return -1;
@@ -2078,7 +2102,7 @@ int Socket::SSLHandshake(int fd, bool server_mode) {
         case SSL_ERROR_WANT_WRITE:
 #if defined(OS_LINUX)
             if (bthread_fd_wait(fd, EPOLLOUT) != 0) {
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
             if (bthread_fd_wait(fd, EVFILT_WRITE) != 0) {
 #endif
                 return -1;
@@ -2246,7 +2270,7 @@ int Socket::OnInputEvent(void* user_data, uint32_t eve
     if (s->fd() < 0) {
 #if defined(OS_LINUX)
         CHECK(!(events & EPOLLIN)) << "epoll_events=" << events;
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
         CHECK((short)events != EVFILT_READ) << "kqueue filter=" << events;
 #endif
         return -1;
@@ -2482,7 +2506,11 @@ void Socket::DebugSocket(std::ostream& os, SocketId id
     {
         int keepidle = 0;
         socklen_t len = sizeof(keepidle);
-#if defined(OS_MACOSX)
+#if defined(OS_FREEBSD)
+        if (getsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &keepidle, &len) == 0) {
+            os << "\ntcp_keepalive_time=" << keepidle;
+        }
+#elif defined(OS_MACOSX)
         if (getsockopt(fd, IPPROTO_TCP, TCP_KEEPALIVE, &keepidle, &len) == 0) {
             os << "\ntcp_keepalive_time=" << keepidle;
         }
@@ -2496,7 +2524,7 @@ void Socket::DebugSocket(std::ostream& os, SocketId id
     {
         int keepintvl = 0;
         socklen_t len = sizeof(keepintvl);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
         if (getsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL, &keepintvl, &len) == 0) {
             os << "\ntcp_keepalive_intvl=" << keepintvl;
         }
@@ -2510,7 +2538,7 @@ void Socket::DebugSocket(std::ostream& os, SocketId id
     {
         int keepcnt = 0;
         socklen_t len = sizeof(keepcnt);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
         if (getsockopt(fd, IPPROTO_TCP, TCP_KEEPCNT, &keepcnt, &len) == 0) {
             os << "\ntcp_keepalive_probes=" << keepcnt;
         }
@@ -2531,7 +2559,22 @@ void Socket::DebugSocket(std::ostream& os, SocketId id
     }
 #endif
 
-#if defined(OS_MACOSX)
+#if defined(OS_FREEBSD)
+    struct tcp_info ti;
+    socklen_t len = sizeof(ti);
+    if (fd >= 0 && getsockopt(fd, IPPROTO_TCP, TCP_INFO, &ti, &len) == 0) {
+        os << "\ntcpi={\n  state=" << (uint32_t)ti.tcpi_state
+           << "\n  snd_wscale=" << (uint32_t)ti.tcpi_snd_wscale
+           << "\n  rcv_wscale=" << (uint32_t)ti.tcpi_rcv_wscale
+           << "\n  options=" << (uint32_t)ti.tcpi_options
+           << "\n  rto=" << ti.tcpi_rto
+           << "\n  snd_mss=" << ti.tcpi_snd_mss
+           << "\n  snd_ssthresh=" << ti.tcpi_snd_ssthresh
+           << "\n  snd_cwnd=" << ti.tcpi_snd_cwnd
+           << "\n  rcv_space=" << ti.tcpi_rcv_space
+           << "\n}";
+    }
+#elif defined(OS_MACOSX)
     struct tcp_connection_info ti;
     socklen_t len = sizeof(ti);
     if (fd >= 0 && getsockopt(fd, IPPROTO_TCP, TCP_CONNECTION_INFO, &ti, &len) == 0) {

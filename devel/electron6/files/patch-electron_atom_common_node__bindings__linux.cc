--- electron/atom/common/node_bindings_linux.cc.orig	2019-09-11 17:30:11 UTC
+++ electron/atom/common/node_bindings_linux.cc
@@ -4,17 +4,31 @@
 
 #include "atom/common/node_bindings_linux.h"
 
+#if !defined(OS_BSD)
 #include <sys/epoll.h>
+#else
+#include <errno.h>
+#include <sys/select.h>
+#include <sys/sysctl.h>
+#include <sys/time.h>
+#include <sys/types.h>
+#endif
 
 namespace atom {
 
 NodeBindingsLinux::NodeBindingsLinux(BrowserEnvironment browser_env)
+#if !defined(OS_BSD)
     : NodeBindings(browser_env), epoll_(epoll_create(1)) {
+#else
+    : NodeBindings(browser_env) {
+#endif
+#if !defined(OS_BSD)
   int backend_fd = uv_backend_fd(uv_loop_);
   struct epoll_event ev = {0};
   ev.events = EPOLLIN;
   ev.data.fd = backend_fd;
   epoll_ctl(epoll_, EPOLL_CTL_ADD, backend_fd, &ev);
+#endif
 }
 
 NodeBindingsLinux::~NodeBindingsLinux() {}
@@ -37,6 +51,7 @@ void NodeBindingsLinux::OnWatcherQueueChanged(uv_loop_
 }
 
 void NodeBindingsLinux::PollEvents() {
+#if !defined(OS_BSD)
   int timeout = uv_backend_timeout(uv_loop_);
 
   // Wait for new libuv events.
@@ -45,6 +60,26 @@ void NodeBindingsLinux::PollEvents() {
     struct epoll_event ev;
     r = epoll_wait(epoll_, &ev, 1, timeout);
   } while (r == -1 && errno == EINTR);
+#else
+  struct timeval tv;
+  int timeout = uv_backend_timeout(uv_loop_);
+  if (timeout != -1) {
+    tv.tv_sec = timeout / 1000;
+    tv.tv_usec = (timeout % 1000) * 1000;
+  }
+
+  fd_set readset;
+  int fd = uv_backend_fd(uv_loop_);
+  FD_ZERO(&readset);
+  FD_SET(fd, &readset);
+
+  // Wait for new libuv events.
+  int r;
+  do {
+    r = select(fd + 1, &readset, nullptr, nullptr,
+               timeout == -1 ? nullptr : &tv);
+   } while (r == -1 && errno == EINTR);
+#endif
 }
 
 // static

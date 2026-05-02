--- src/butil/endpoint.cpp.orig	2026-02-23 02:11:29 UTC
+++ src/butil/endpoint.cpp
@@ -30,7 +30,7 @@
 #include <memory>
 #include <gflags/gflags.h>
 #include <sys/poll.h>
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 #include <sys/event.h>                           // kevent(), kqueue()
 #endif
 #include "butil/build_config.h"                // OS_MACOSX
@@ -403,7 +403,7 @@ static short epoll_to_poll_events(uint32_t epoll_event
     CHECK_EQ((uint32_t)poll_events, epoll_events);
     return poll_events;
 }
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
 short kqueue_to_poll_events(int kqueue_events) {
     //TODO: add more values?
     short poll_events = 0;
@@ -421,7 +421,7 @@ int pthread_fd_wait(int fd, unsigned events,
                     const timespec* abstime) {
 #if defined(OS_LINUX)
     const short poll_events = epoll_to_poll_events(events);
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
     const short poll_events = kqueue_to_poll_events(events);
 #endif
     if (poll_events == 0) {
@@ -482,7 +482,7 @@ int pthread_timed_connect(int sockfd, const struct soc
     }
 #if defined(OS_LINUX)
     if (pthread_fd_wait(sockfd, EPOLLOUT, abstime) < 0) {
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
     if (pthread_fd_wait(sockfd, EVFILT_WRITE, abstime) < 0) {
 #endif
         return -1;

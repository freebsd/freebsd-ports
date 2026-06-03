--- src/bthread/fd.cpp.orig	2026-02-23 02:11:29 UTC
+++ src/bthread/fd.cpp
@@ -22,7 +22,7 @@
 #include "butil/compat.h"
 #include <new>                                   // std::nothrow
 #include <sys/poll.h>                            // poll()
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 #include <sys/types.h>                           // struct kevent
 #include <sys/event.h>                           // kevent(), kqueue()
 #endif
@@ -133,7 +133,7 @@ class EpollThread { (public)
         }
 #if defined(OS_LINUX)
         _epfd = epoll_create(epoll_size);
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
         _epfd = kqueue();
 #endif
         _start_mutex.unlock();
@@ -181,7 +181,7 @@ class EpollThread { (public)
         epoll_event evt = { EPOLLOUT, { NULL } };
         if (epoll_ctl(saved_epfd, EPOLL_CTL_ADD,
                       closing_epoll_pipe[1], &evt) < 0) {
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
         struct kevent kqueue_event;
         EV_SET(&kqueue_event, closing_epoll_pipe[1], EVFILT_WRITE, EV_ADD | EV_ENABLE,
                 0, 0, NULL);
@@ -257,7 +257,7 @@ class EpollThread { (public)
             return -1;
         }
 # endif
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
         struct kevent kqueue_event;
         EV_SET(&kqueue_event, fd, events, EV_ADD | EV_ENABLE | EV_ONESHOT,
                 0, 0, butex);
@@ -299,7 +299,7 @@ class EpollThread { (public)
         }
 #if defined(OS_LINUX)
         epoll_ctl(_epfd, EPOLL_CTL_DEL, fd, NULL);
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
         struct kevent evt;
         EV_SET(&evt, fd, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
         kevent(_epfd, &evt, 1, NULL, 0, NULL);
@@ -325,7 +325,7 @@ class EpollThread { (public)
         const size_t MAX_EVENTS = 32;
 #if defined(OS_LINUX)
         epoll_event* e = new (std::nothrow) epoll_event[MAX_EVENTS];
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
         typedef struct kevent KEVENT;
         struct kevent* e = new (std::nothrow) KEVENT[MAX_EVENTS];
 #endif
@@ -343,7 +343,7 @@ class EpollThread { (public)
             const int epfd = _epfd;
 #if defined(OS_LINUX)
             const int n = epoll_wait(epfd, e, MAX_EVENTS, -1);
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
             const int n = kevent(epfd, NULL, 0, e, MAX_EVENTS, NULL);
 #endif
             if (_stop) {
@@ -383,7 +383,7 @@ class EpollThread { (public)
                 EpollButex* butex = pbutex ?
                     pbutex->load(butil::memory_order_consume) : NULL;
 # endif
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
                 EpollButex* butex = static_cast<EpollButex*>(e[i].udata);
 #endif
                 if (butex != NULL && butex != CLOSING_GUARD) {
@@ -495,7 +495,7 @@ int bthread_connect(int sockfd, const sockaddr* serv_a
     }
 #if defined(OS_LINUX)
     if (bthread_fd_wait(sockfd, EPOLLOUT) < 0) {
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
     if (bthread_fd_wait(sockfd, EVFILT_WRITE) < 0) {
 #endif
         return -1;
@@ -531,7 +531,7 @@ int bthread_timed_connect(int sockfd, const struct soc
     }
 #if defined(OS_LINUX)
     if (bthread_fd_timedwait(sockfd, EPOLLOUT, abstime) < 0) {
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
     if (bthread_fd_timedwait(sockfd, EVFILT_WRITE, abstime) < 0) {
 #endif
         return -1;

--- base/message_loop/message_pump_epoll.cc.orig	2025-10-21 20:19:54 UTC
+++ base/message_loop/message_pump_epoll.cc
@@ -44,7 +44,7 @@ constexpr std::pair<uint32_t, short int> kEpollToPollE
 std::atomic_bool g_use_poll = false;
 
 constexpr std::pair<uint32_t, short int> kEpollToPollEvents[] = {
-    {EPOLLIN, POLLIN},   {EPOLLOUT, POLLOUT}, {EPOLLRDHUP, POLLRDHUP},
+    {EPOLLIN, POLLIN},   {EPOLLOUT, POLLOUT},
     {EPOLLPRI, POLLPRI}, {EPOLLERR, POLLERR}, {EPOLLHUP, POLLHUP}};
 
 void SetEventsForPoll(const uint32_t epoll_events, struct pollfd* poll_entry) {

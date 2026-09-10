--- base/message_loop/message_pump_epoll.h.orig	2026-08-24 20:59:34 UTC
+++ base/message_loop/message_pump_epoll.h
@@ -49,7 +49,11 @@ BASE_FEATURE(kUsePollForMessagePumpEpoll,
 // Caveat: Since both we and the kernel need to walk the list of all fds at
 // every call, don't do it when we have too many FDs.
 BASE_FEATURE(kUsePollForMessagePumpEpoll,
+#if BUILDFLAG(IS_BSD)
+             base::FEATURE_ENABLED_BY_DEFAULT);
+#else
              base::FEATURE_DISABLED_BY_DEFAULT);
+#endif
 
 // A MessagePump implementation suitable for I/O message loops on Linux-based
 // systems with epoll API support.

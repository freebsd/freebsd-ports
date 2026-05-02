--- src/brpc/event_dispatcher.cpp.orig	2026-02-23 02:11:29 UTC
+++ src/brpc/event_dispatcher.cpp
@@ -101,7 +101,7 @@ void IOEventData::BeforeRecycled() {
 
 #if defined(OS_LINUX)
     #include "brpc/event_dispatcher_epoll.cpp"
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
     #include "brpc/event_dispatcher_kqueue.cpp"
 #else
     #error Not implemented

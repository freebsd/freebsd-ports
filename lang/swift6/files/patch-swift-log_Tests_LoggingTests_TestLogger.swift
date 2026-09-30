--- swift-log/Tests/LoggingTests/TestLogger.swift.orig	2023-12-07 18:42:43 UTC
+++ swift-log/Tests/LoggingTests/TestLogger.swift
@@ -363,6 +363,10 @@ public class MDC {
         return Int(pthread_mach_thread_np(pthread_self()))
         #elseif os(Windows)
         return Int(GetCurrentThreadId())
+        #elseif os(FreeBSD)
+        return Int(pthread_getthreadid_np())
+        #elseif os(OpenBSD)
+        return Int(bitPattern: pthread_self())
         #else
         return Int(pthread_self())
         #endif

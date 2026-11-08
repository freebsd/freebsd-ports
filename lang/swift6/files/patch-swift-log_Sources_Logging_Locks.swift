--- swift-log/Sources/Logging/Locks.swift.orig	2023-12-07 18:42:43 UTC
+++ swift-log/Sources/Logging/Locks.swift
@@ -52,6 +52,9 @@ internal final class Lock {
     #elseif os(Windows)
     fileprivate let mutex: UnsafeMutablePointer<SRWLOCK> =
         UnsafeMutablePointer.allocate(capacity: 1)
+    #elseif os(FreeBSD) || os(OpenBSD)
+    fileprivate let mutex: UnsafeMutablePointer<pthread_mutex_t?> =
+        UnsafeMutablePointer.allocate(capacity: 1)
     #else
     fileprivate let mutex: UnsafeMutablePointer<pthread_mutex_t> =
         UnsafeMutablePointer.allocate(capacity: 1)
@@ -64,9 +67,17 @@ internal final class Lock {
         #elseif os(Windows)
         InitializeSRWLock(self.mutex)
         #else
+        #if os(FreeBSD) || os(OpenBSD)
+        var attr = pthread_mutexattr_t(bitPattern: 0)
+        #else
         var attr = pthread_mutexattr_t()
+        #endif
         pthread_mutexattr_init(&attr)
+        #if os(FreeBSD) || os(OpenBSD)
+        pthread_mutexattr_settype(&attr, .init(PTHREAD_MUTEX_ERRORCHECK.rawValue))
+        #else
         pthread_mutexattr_settype(&attr, .init(PTHREAD_MUTEX_ERRORCHECK))
+        #endif
 
         let err = pthread_mutex_init(self.mutex, &attr)
         precondition(err == 0, "\(#function) failed in pthread_mutex with error \(err)")
@@ -155,6 +166,9 @@ internal final class ReadWriteLock {
     fileprivate let rwlock: UnsafeMutablePointer<SRWLOCK> =
         UnsafeMutablePointer.allocate(capacity: 1)
     fileprivate var shared: Bool = true
+    #elseif os(FreeBSD) || os(OpenBSD)
+    fileprivate let rwlock: UnsafeMutablePointer<pthread_rwlock_t?> =
+        UnsafeMutablePointer.allocate(capacity: 1)
     #else
     fileprivate let rwlock: UnsafeMutablePointer<pthread_rwlock_t> =
         UnsafeMutablePointer.allocate(capacity: 1)

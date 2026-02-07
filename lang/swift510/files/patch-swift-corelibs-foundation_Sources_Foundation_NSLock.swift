--- swift-corelibs-foundation/Sources/Foundation/NSLock.swift.orig	2024-05-31 00:46:27 UTC
+++ swift-corelibs-foundation/Sources/Foundation/NSLock.swift
@@ -26,7 +26,7 @@ private typealias _ConditionVariablePointer = UnsafeMu
 private typealias _MutexPointer = UnsafeMutablePointer<SRWLOCK>
 private typealias _RecursiveMutexPointer = UnsafeMutablePointer<CRITICAL_SECTION>
 private typealias _ConditionVariablePointer = UnsafeMutablePointer<CONDITION_VARIABLE>
-#elseif CYGWIN || os(OpenBSD)
+#elseif CYGWIN || os(OpenBSD) || os(FreeBSD)
 private typealias _MutexPointer = UnsafeMutablePointer<pthread_mutex_t?>
 private typealias _RecursiveMutexPointer = UnsafeMutablePointer<pthread_mutex_t?>
 private typealias _ConditionVariablePointer = UnsafeMutablePointer<pthread_cond_t?>
@@ -248,14 +248,14 @@ open class NSRecursiveLock: NSObject, NSLocking {
         InitializeConditionVariable(timeoutCond)
         InitializeSRWLock(timeoutMutex)
 #else
-#if CYGWIN || os(OpenBSD)
+#if CYGWIN || os(OpenBSD) || os(FreeBSD)
         var attrib : pthread_mutexattr_t? = nil
 #else
         var attrib = pthread_mutexattr_t()
 #endif
         withUnsafeMutablePointer(to: &attrib) { attrs in
             pthread_mutexattr_init(attrs)
-#if os(OpenBSD)
+#if os(OpenBSD) || os(FreeBSD)
             let type = Int32(PTHREAD_MUTEX_RECURSIVE.rawValue)
 #else
             let type = Int32(PTHREAD_MUTEX_RECURSIVE)

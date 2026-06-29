--- swift-corelibs-foundation/Sources/Foundation/Thread.swift.orig	2024-05-31 00:46:27 UTC
+++ swift-corelibs-foundation/Sources/Foundation/Thread.swift
@@ -214,7 +214,7 @@ open class Thread : NSObject {
         get { _attrStorage.value }
         set { _attrStorage.value = newValue }
     }
-#elseif CYGWIN || os(OpenBSD)
+#elseif CYGWIN || os(OpenBSD) || os(FreeBSD)
     internal var _attr : pthread_attr_t? = nil
 #else
     internal var _attr = pthread_attr_t()
@@ -254,7 +254,7 @@ open class Thread : NSObject {
             _status = .finished
             return
         }
-#if CYGWIN || os(OpenBSD)
+#if CYGWIN || os(OpenBSD) || os(FreeBSD)
         if let attr = self._attr {
             _thread = self.withRetainedReference {
               return _CFThreadCreate(attr, NSThreadStart, $0)
@@ -362,7 +362,7 @@ open class Thread : NSObject {
         let maxSupportedStackDepth = 128;
         let addrs = UnsafeMutablePointer<UnsafeMutableRawPointer?>.allocate(capacity: maxSupportedStackDepth)
         defer { addrs.deallocate() }
-#if os(Android) || os(OpenBSD)
+#if os(Android) || os(OpenBSD) || os(FreeBSD)
         let count = 0
 #elseif os(Windows)
         let count = RtlCaptureStackBackTrace(0, DWORD(maxSupportedStackDepth),
@@ -383,7 +383,7 @@ open class Thread : NSObject {
     }
 
     open class var callStackSymbols: [String] {
-#if os(Android) || os(OpenBSD)
+#if os(Android) || os(OpenBSD) || os(FreeBSD)
         return []
 #elseif os(Windows)
         let hProcess: HANDLE = GetCurrentProcess()

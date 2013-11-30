--- ./ext/libclementine-common/core/closure.cpp.orig	2013-11-24 15:58:51.321696435 -0800
+++ ./ext/libclementine-common/core/closure.cpp	2013-11-24 15:59:00.552695416 -0800
@@ -33,7 +33,7 @@
 CallbackClosure::CallbackClosure(
     QObject* sender,
     const char* signal,
-    std::tr1::function<void()> callback)
+    std::function<void()> callback)
   : ClosureBase(new ObjectHelper(sender, signal, this)),
     callback_(callback) {
 }
@@ -67,7 +67,7 @@
 _detail::ClosureBase* NewClosure(
     QObject* sender,
     const char* signal,
-    std::tr1::function<void()> callback) {
+    std::function<void()> callback) {
   return new _detail::CallbackClosure(
       sender, signal, callback);
 }

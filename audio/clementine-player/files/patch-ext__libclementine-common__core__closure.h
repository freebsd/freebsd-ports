--- ./ext/libclementine-common/core/closure.h.orig	2013-11-24 15:58:19.241698287 -0800
+++ ./ext/libclementine-common/core/closure.h	2013-11-24 15:58:38.634697259 -0800
@@ -18,7 +18,7 @@
 #ifndef CLOSURE_H
 #define CLOSURE_H
 
-#include <tr1/functional>
+#include <functional>
 
 #include <QMetaMethod>
 #include <QObject>
@@ -158,12 +158,12 @@
   CallbackClosure(
       QObject* sender,
       const char* signal,
-      std::tr1::function<void()> callback);
+      std::function<void()> callback);
 
   virtual void Invoke();
 
  private:
-  std::tr1::function<void()> callback_;
+  std::function<void()> callback_;
 };
 
 }  // namespace _detail
@@ -194,13 +194,13 @@
 _detail::ClosureBase* NewClosure(
     QObject* sender,
     const char* signal,
-    std::tr1::function<void()> callback);
+    std::function<void()> callback);
 
 template <typename... Args>
 _detail::ClosureBase* NewClosure(
     QObject* sender,
     const char* signal,
-    std::tr1::function<void(Args...)> callback,
+    std::function<void(Args...)> callback,
     const Args&... args) {
   return NewClosure(sender, signal, boost::bind(callback, args...));
 }

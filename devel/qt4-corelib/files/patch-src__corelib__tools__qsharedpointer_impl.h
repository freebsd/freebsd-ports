--- src/corelib/tools/qsharedpointer_impl.h.orig	2012-11-23 15:08:47.000000000 +0800
+++ src/corelib/tools/qsharedpointer_impl.h	2012-11-23 15:10:22.000000000 +0800
@@ -592,7 +592,7 @@
 #ifndef QT_NO_QOBJECT
     // special constructor that is enabled only if X derives from QObject
     template <class X>
-    inline QWeakPointer(X *ptr) : d(ptr ? d->getAndRef(ptr) : 0), value(ptr)
+    inline QWeakPointer(X *ptr) : d(ptr ? Data::getAndRef(ptr) : 0), value(ptr)
     { }
 #endif
     template <class X>

--- src/include/cbthreadpool.h.orig	2013-11-17 20:34:15.000000000 +0100
+++ src/include/cbthreadpool.h	2015-09-16 21:19:53.385265000 +0200
@@ -15,6 +15,12 @@
 #include "settings.h"
 #include "prep.h"
 
+#if defined(__has_feature) && __has_feature(cxx_noexcept)
+#define NOEXCEPT noexcept
+#else
+#define NOEXCEPT throw()
+#endif
+
 /// A Thread Pool implementation
 class DLLIMPORT cbThreadPool
 {
@@ -94,11 +100,11 @@ class DLLIMPORT cbThreadPool
 
       public:
         explicit CountedPtr(T *p = 0);
-        CountedPtr(const CountedPtr<T> &p) throw();
-        ~CountedPtr() throw();
-        CountedPtr<T> &operator = (const CountedPtr<T> &p) throw();
-        T &operator * () const throw();
-        T *operator -> () const throw();
+        CountedPtr(const CountedPtr<T> &p) NOEXCEPT;
+        ~CountedPtr() NOEXCEPT;
+        CountedPtr<T> &operator = (const CountedPtr<T> &p) NOEXCEPT;
+        T &operator * () const NOEXCEPT;
+        T *operator -> () const NOEXCEPT;
 
       private:
         void dispose();
@@ -281,7 +287,7 @@ inline cbThreadPool::CountedPtr<T>::Coun
 }
 
 template <typename T>
-inline cbThreadPool::CountedPtr<T>::CountedPtr(const CountedPtr<T> &p) throw()
+inline cbThreadPool::CountedPtr<T>::CountedPtr(const CountedPtr<T> &p) NOEXCEPT
 : ptr(p.ptr),
   count(p.count)
 {
@@ -289,13 +295,13 @@ inline cbThreadPool::CountedPtr<T>::Coun
 }
 
 template <typename T>
-inline cbThreadPool::CountedPtr<T>::~CountedPtr() throw()
+inline cbThreadPool::CountedPtr<T>::~CountedPtr() NOEXCEPT
 {
   dispose();
 }
 
 template <typename T>
-inline cbThreadPool::CountedPtr<T> &cbThreadPool::CountedPtr<T>::operator = (const CountedPtr<T> &p) throw()
+inline cbThreadPool::CountedPtr<T> &cbThreadPool::CountedPtr<T>::operator = (const CountedPtr<T> &p) NOEXCEPT
 {
   if (this != &p)
   {
@@ -309,13 +315,13 @@ inline cbThreadPool::CountedPtr<T> &cbTh
 }
 
 template <typename T>
-inline T &cbThreadPool::CountedPtr<T>::operator * () const throw()
+inline T &cbThreadPool::CountedPtr<T>::operator * () const NOEXCEPT
 {
   return *ptr;
 }
 
 template <typename T>
-inline T *cbThreadPool::CountedPtr<T>::operator -> () const throw()
+inline T *cbThreadPool::CountedPtr<T>::operator -> () const NOEXCEPT
 {
   return ptr;
 }

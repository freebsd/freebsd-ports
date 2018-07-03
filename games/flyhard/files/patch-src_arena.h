--- src/arena.h.orig	2008-11-23 10:56:52 UTC
+++ src/arena.h
@@ -60,7 +60,7 @@ class arena_ptr
 {
   friend class arena;
 public:
-  operator bool() const   {return m_ptr.lock();}
+  operator bool() const   {return m_ptr.lock() != nullptr;}
   T &operator *() const   {return **(m_ptr.lock());}
   T *get() const          {return *(m_ptr.lock());}
   arena_ptr<T>(const arena_ptr<T> &_){m_ptr=_.m_ptr;}

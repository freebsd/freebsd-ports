--- lib/linkedlist.h.orig	Mon Aug 16 16:53:58 2004
+++ lib/linkedlist.h	Mon Aug 16 17:08:25 2004
@@ -89,7 +89,7 @@
     list_iterator(__list_core * x) : __list_iter(x) { }
     T * next()          { return (T *) __list_iter::next(); }
     T * remove()        { return (T *) __list_iter::remove(); }
-    T * get(void)       { return (T *) __list_iter::get(); }
+    //T * get(void)       { return (T *) __list_iter::get(); }
     T * set(int x)      { return (T *) __list_iter::set(x); }
 };
     
@@ -97,7 +97,7 @@
 {    
 public:
     int add(T *x)         { return __list_core::add((void *) x); }
-    int add(int w, T * x) { return __list_core::insert(w, (void *) x); }
+    //int add(int w, T * x) { return __list_core::insert(w, (void *) x); }
     T * get(int idx)      { return (T *) __list_core::get(idx); }
     T * remove(int idx)   { return (T *) __list_core::remove(idx); }
     bool remove(T * d)    { return __list_core::remove(d); }

--- hotspot/src/os/bsd/vm/os_bsd.hpp.orig	2013-09-06 18:22:03 UTC
+++ hotspot/src/os/bsd/vm/os_bsd.hpp
@@ -222,6 +222,13 @@ class Bsd {
   static jlong fast_thread_cpu_time(clockid_t clockid);
 #endif
 
+  // pthread_cond clock suppport
+  private:
+  static pthread_condattr_t _condattr[1];
+
+  public:
+  static pthread_condattr_t* condAttr() { return _condattr; }
+
   // Stack repair handling
 
   // none present
@@ -287,7 +294,7 @@ class PlatformEvent : public CHeapObj<mt
   public:
     PlatformEvent() {
       int status;
-      status = pthread_cond_init (_cond, NULL);
+      status = pthread_cond_init (_cond, os::Bsd::condAttr());
       assert_status(status == 0, status, "cond_init");
       status = pthread_mutex_init (_mutex, NULL);
       assert_status(status == 0, status, "mutex_init");
@@ -302,14 +309,19 @@ class PlatformEvent : public CHeapObj<mt
     void park () ;
     void unpark () ;
     int  TryPark () ;
-    int  park (jlong millis) ;
+    int  park (jlong millis) ; // relative timed-wait only
     void SetAssociation (Thread * a) { _Assoc = a ; }
 };
 
 class PlatformParker : public CHeapObj<mtInternal> {
   protected:
+    enum {
+        REL_INDEX = 0,
+        ABS_INDEX = 1
+    };
+    int _cur_index;  // which cond is in use: -1, 0, 1
     pthread_mutex_t _mutex [1] ;
-    pthread_cond_t  _cond  [1] ;
+    pthread_cond_t  _cond  [2] ; // one for relative times and one for abs.
 
   public:       // TODO-FIXME: make dtor private
     ~PlatformParker() { guarantee (0, "invariant") ; }
@@ -317,10 +329,13 @@ class PlatformParker : public CHeapObj<m
   public:
     PlatformParker() {
       int status;
-      status = pthread_cond_init (_cond, NULL);
-      assert_status(status == 0, status, "cond_init");
+      status = pthread_cond_init (&_cond[REL_INDEX], os::Bsd::condAttr());
+      assert_status(status == 0, status, "cond_init rel");
+      status = pthread_cond_init (&_cond[ABS_INDEX], NULL);
+      assert_status(status == 0, status, "cond_init abs");
       status = pthread_mutex_init (_mutex, NULL);
       assert_status(status == 0, status, "mutex_init");
+      _cur_index = -1; // mark as unused
     }
 };
 

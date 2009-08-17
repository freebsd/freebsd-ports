--- ev++.h.orig	2009-08-17 19:12:04.000000000 +0400
+++ ev++.h	2009-08-17 19:20:40.000000000 +0400
@@ -76,7 +76,7 @@
     ASYNC    = EV_ASYNC,
     EMBED    = EV_EMBED,
 #   undef ERROR // some systems stupidly #define ERROR
-    ERROR    = EV_ERROR,
+    ERROR    = EV_ERROR
   };
 
   enum
@@ -464,7 +464,7 @@
     }
 
     template<class K, void (K::*method)(watcher &w, int)>
-    static void method_thunk (EV_P_ ev_watcher *w, int revents)
+    static void method_thunk (struct ev_loop *, ev_watcher *w, int revents)
     {
       (static_cast<K *>(w->data)->*method)
         (*static_cast<watcher *>(w), revents);
@@ -478,9 +478,9 @@
     }
 
     template<class K, void (K::*method)()>
-    static void method_noargs_thunk (EV_P_ ev_watcher *w, int revents)
+    static void method_noargs_thunk (struct ev_loop *, ev_watcher *w, int /*revents*/)
     {
-      static_cast<K *>(w->data)->*method
+      (static_cast<K *>(w->data)->*method)
         ();
     }
 

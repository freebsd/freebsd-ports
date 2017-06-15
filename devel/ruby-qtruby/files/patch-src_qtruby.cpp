Fix bogus pointer comparison.

--- src/qtruby.cpp.orig	2017-01-18 20:21:44 UTC
+++ src/qtruby.cpp
@@ -2094,7 +2094,7 @@ isObject(VALUE /*self*/, VALUE obj)
 {
     void * ptr = 0;
     ptr = value_to_ptr(obj);
-    return (ptr > 0 ? Qtrue : Qfalse);
+    return (ptr ? Qtrue : Qfalse);
 }
 
 static VALUE

--- src/gdb/gdb/common/selftest.h.orig	2018-01-18 18:38:13.161295000 +0300
+++ src/gdb/gdb/common/selftest.h	2018-01-18 18:38:29.032519000 +0300
@@ -31,6 +31,7 @@
 
 struct selftest
 {
+  virtual ~selftest() {}
   virtual void operator() () const = 0;
 };
 

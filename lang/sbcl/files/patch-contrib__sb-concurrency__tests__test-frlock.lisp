--- contrib/sb-concurrency/tests/test-frlock.lisp.orig	2012-12-01 06:32:36.000000000 -0500
+++ contrib/sb-concurrency/tests/test-frlock.lisp	2012-12-15 16:23:03.000000000 -0500
@@ -80,7 +80,7 @@
       (values (cdr w-e!) (cdr r-e!))))
 
 #+sb-thread
-(deftest* (frlock.1 :fails-on :win32)
+(deftest* (frlock.1 :fails-on (or :freebsd :win32))
     (handler-case
         (sb-ext:with-timeout 60 (test-frlocks))
       (sb-ext:timeout (c)

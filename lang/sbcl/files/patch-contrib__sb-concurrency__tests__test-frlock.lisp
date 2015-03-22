--- contrib/sb-concurrency/tests/test-frlock.lisp.orig	2015-02-27 19:49:46.000000000 +0900
+++ contrib/sb-concurrency/tests/test-frlock.lisp	2015-03-07 18:14:12.000000000 +0900
@@ -85,7 +85,7 @@
       (values (cdr w-e!) (cdr r-e!))))
 
 #+sb-thread
-(deftest* (frlock.1 :fails-on :win32)
+(deftest* (frlock.1 :fails-on :(or :freebsd :win32))
     (handler-case
         (sb-ext:with-timeout 60 (test-frlocks))
       (sb-ext:timeout (c)

--- contrib/sb-posix/posix-tests.lisp.orig	Thu Feb  5 01:22:59 2004
+++ contrib/sb-posix/posix-tests.lisp	Thu Feb  5 01:23:31 2004
@@ -82,13 +82,6 @@
     (sb-posix:syscall-error (c)
       (sb-posix:syscall-errno c)))
   #.sb-posix::eexist)
-
-(deftest mkdir.error.3
-  (handler-case
-      (sb-posix:mkdir "/almost-certainly-does-not-exist" 0)
-    (sb-posix:syscall-error (c)
-      (sb-posix:syscall-errno c)))
-  #.sb-posix::eacces)
 
 (deftest rmdir.1
   (let ((dne (make-pathname :directory '(:relative "rmdir.does-not-exist.1"))))

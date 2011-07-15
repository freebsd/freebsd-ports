--- contrib/sb-posix/posix-tests.lisp.orig	2011-07-14 16:51:21.000000000 -0700
+++ contrib/sb-posix/posix-tests.lisp	2011-07-14 16:51:36.000000000 -0700
@@ -172,13 +172,13 @@
       (sb-posix:rmdir #-win32 "/" #+win32 "C:/")
     (sb-posix:syscall-error (c)
       (sb-posix:syscall-errno c)))
-  #+darwin
+  #+(or darwin freebsd)
   #.sb-posix:eisdir
   #+win32
   #.sb-posix::eacces
   #+sunos
   #.sb-posix::einval
-  #-(or darwin win32 sunos)
+  #-(or darwin freebsd win32 sunos)
   #.sb-posix::ebusy)
 
 (deftest rmdir.error.4

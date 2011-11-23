--- contrib/sb-posix/posix-tests.lisp.orig	2011-11-06 15:31:02.000000000 -0500
+++ contrib/sb-posix/posix-tests.lisp	2011-11-22 10:26:13.000000000 -0500
@@ -174,7 +174,7 @@
       (typep
        (sb-posix:syscall-errno c)
        '(member
-         #+darwin
+         #+(or darwin freebsd)
          #.sb-posix:eisdir
          #+win32
          #.sb-posix::eacces
@@ -182,7 +182,7 @@
          #.sb-posix::enotempty
          #+sunos
          #.sb-posix::einval
-         #-(or darwin win32 sunos)
+         #-(or darwin freebsd win32 sunos)
          #.sb-posix::ebusy)))) t)
 
 (deftest rmdir.error.4

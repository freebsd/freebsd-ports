--- swank-sbcl.lisp.orig	Wed Apr 27 21:16:21 2005
+++ swank-sbcl.lisp	Tue May 24 17:33:21 2005
@@ -43,6 +43,7 @@
 
 (defimplementation preferred-communication-style ()
   (if (and (member :sb-thread *features*)
+          #+linux
            (not (sb-alien:extern-alien "linux_no_threads_p" sb-alien:boolean)))
       :spawn
       :fd-handler))

--- code/unix-bindings/unix.lisp~	2004-01-08 16:34:05.000000000 +0100
+++ code/unix-bindings/unix.lisp	2004-10-16 16:06:28.000000000 +0200
@@ -38,7 +38,8 @@
 (defmacro def-c-call-out (sym &body args)
   `(def-call-out ,sym (:language :stdc) ,@args))
 
-#.(when (> (read-from-string (lisp-implementation-version)) 2.30)
+#.(when (> (read-from-string (subseq (lisp-implementation-version)
+                                     0 4)) 2.30)
     (push :clisp-newer-than-2.30 *features*)
     (values))
 

--- path.lisp.orig	2009-06-10 11:40:23.000000000 +0400
+++ path.lisp	2009-06-10 11:40:43.000000000 +0400
@@ -57,7 +57,7 @@
                           path)))
     #+cmu (eq :directory (unix:unix-file-kind (namestring path)))
     #+lispworks (lw:file-directory-p path)
-    #+sbcl (eq :directory (sb-unix:unix-file-kind (namestring path)))
+    #+sbcl (eq :directory (native-file-kind (namestring path)))
     #-(or allegro clisp cmu lispworks sbcl)
     (probe-file path)))
 

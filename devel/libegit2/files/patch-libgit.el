--- libgit.el.orig	2020-05-15 17:59:08 UTC
+++ libgit.el
@@ -41,7 +41,7 @@
   "Directory where the libegit2 dynamic module file should be built.")
 
 (defvar libgit--module-file
-  (expand-file-name (concat "libegit2" module-file-suffix) libgit--build-dir)
+  (expand-file-name (concat "libegit2" module-file-suffix) "/usr/local/share/emacs/27.1/site-lisp")
   "Path to the libegit2 dynamic module file.")
 
 (defun libgit--configure ()

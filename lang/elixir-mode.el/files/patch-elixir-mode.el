--- elixir-mode.el.orig	2023-07-29 10:52:04 UTC
+++ elixir-mode.el
@@ -473,6 +473,7 @@ is used to limit the scan."
 (defconst elixir--version
   (eval-when-compile
     (require 'lisp-mnt)
+    (require 'bytecomp)
     (let ((file (or byte-compile-current-file
 		    load-file-name
 		    (buffer-file-name))))

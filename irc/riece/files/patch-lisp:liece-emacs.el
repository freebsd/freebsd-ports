--- lisp/liece-emacs.el.orig	Thu Sep 21 06:40:18 2000
+++ lisp/liece-emacs.el	Sun Oct  6 05:12:38 2002
@@ -34,6 +34,7 @@
 
 (eval-when-compile (ignore-errors (require 'image)))
 
+(require 'pces)
 (require 'derived)
 
 (eval-and-compile

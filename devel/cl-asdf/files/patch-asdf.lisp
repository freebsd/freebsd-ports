--- asdf.lisp.orig	Thu Mar 20 13:58:09 2003
+++ asdf.lisp	Thu Mar 20 13:58:49 2003
@@ -322,8 +322,7 @@
 	
 (defvar *central-registry*
   '(*default-pathname-defaults*
-    #+nil "/home/dan/src/sourceforge/cclan/asdf/systems/"
-    #+nil "telent:asdf;systems;"))
+    "/usr/local/lib/common-lisp/system-registry/"))
 
 (defun sysdef-central-registry-search (system)
   (let ((name (coerce-name system)))

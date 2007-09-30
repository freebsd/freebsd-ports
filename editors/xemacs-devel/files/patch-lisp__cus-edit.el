--- lisp/cus-edit.el.orig        Tue Jun 26 04:10:18 2007
+++ lisp/cus-edit.el     Tue Jun 26 04:14:52 2007
@@ -3756,6 +3756,8 @@
 ;;;###autoload
 (defun custom-save-all ()
   "Save all customizations in `custom-file'."
+  (when init-file-had-error
+    (error "Cannot save customizations; init file was not fully loaded"))
   (let ((inhibit-read-only t))
     (custom-save-variables)
     (custom-save-faces)

--- lisp/xtla-defs.el.orig	Sun Jun 27 17:29:25 2004
+++ lisp/xtla-defs.el	Sun Jun 27 17:31:06 2004
@@ -960,13 +960,13 @@
   :group 'xtla)
 
 ;;;###autoload
-(defcustom tla-diff-executable "diff"
+(defcustom tla-diff-executable "gdiff"
   "*The name of the diff executable"
   :type 'string
   :group 'xtla)
 
 ;;;###autoload
-(defcustom tla-patch-executable "patch"
+(defcustom tla-patch-executable "gpatch"
   "*The name of the patch executable"
   :type 'string
   :group 'xtla)

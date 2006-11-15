--- speedbar/sb-info.el.orig	Mon Nov 13 11:30:08 2006
+++ speedbar/sb-info.el	Mon Nov 13 11:30:38 2006
@@ -247,9 +247,10 @@
   (Info-speedbar-hierarchy-buttons nil 0)
   )
 
+(provide 'sb-info)
+
 ;;; Overriding preinstalled code.
 ;;;###autoload
 (eval-after-load "info" '(require 'sb-info))
 
-(provide 'sb-info)
 ;;; sb-info.el ends here

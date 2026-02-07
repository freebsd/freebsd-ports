--- tablist.el.orig	2022-05-06 02:14:20 UTC
+++ tablist.el
@@ -989,7 +989,7 @@ Optional REVERT-P means, revert the display afterwards
     kmap))
 
 (define-minor-mode tablist-edit-column-minor-mode
-  "" nil nil nil
+  "Toggle `tablist-edit-column-minor-mode'." nil nil nil
   (unless (or tablist-minor-mode
               (derived-mode-p 'tablist-mode))
     (error "Not in a tablist buffer"))

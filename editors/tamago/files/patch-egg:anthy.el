--- egg/anthy.el.orig	Thu Aug  8 17:11:22 2002
+++ egg/anthy.el	Sun Jul  4 23:48:18 2004
@@ -118,8 +118,8 @@
 	(save-excursion
 	  (set-buffer buf)
 	  (erase-buffer)
-	  (buffer-disable-undo))))
-  (anthyipc-get-greeting anthy-proc)
+	  (buffer-disable-undo))
+  (anthyipc-get-greeting anthy-proc)))
   (anthyipc-new-context anthy-proc))
 
 ;;; XXX: Don't kill buffer (for now) so that I can debug this program

--- lisp/textmodes/ispell.el.orig	2018-05-25 08:53:30 UTC
+++ lisp/textmodes/ispell.el
@@ -1111,7 +1111,12 @@ dictionary from that list was found."
 				 null-device
 				 t
 				 nil
-				 "-D")
+                                 ;; Hunspell 1.7.0 (and later?) won't
+                                 ;; show LOADED DICTIONARY unless
+                                 ;; there's at least one file argument
+                                 ;; on the command line.  So we feed
+                                 ;; it with the null device.
+				 "-D" null-device)
 	    (buffer-string))
 	  "[\n\r]+"
 	  t))

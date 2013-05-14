--- src-util/anthy.el.orig	2013-05-15 01:57:21.000000000 +0900
+++ src-util/anthy.el	2013-05-15 01:58:25.000000000 +0900
@@ -892,7 +892,7 @@
 	 ((event-matches-key-specifier-p event 'backspace) 8)
 	 (t
 	  (char-to-int (event-to-character event)))))
-    last-command-char))
+    last-command-event))
 
 ;;
 ;;

Index: cmdloop.el
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/lisp/cmdloop.el,v
retrieving revision 1.18
retrieving revision 1.19
diff -u -r1.18 -r1.19
--- lisp/cmdloop.el	2005/06/26 18:04:49	1.18
+++ lisp/cmdloop.el	2006/01/08 20:00:43	1.19
@@ -579,7 +579,8 @@
 		 (setq char (aref translated 0)))))
       (cond ((null char))
 	    ((not (characterp char))
-	     (setq unread-command-events (list char)
+	     ;; XEmacs change; event instead of char. 
+	     (setq unread-command-events (list event)
 		   done t))
 ; 	    ((/= (logand char ?\M-\^@) 0)
 ; 	     ;; Turn a meta-character into a character with the 0200 bit set.
@@ -598,7 +599,8 @@
 	    ((and (not first) (eq char ?\C-m))
 	     (setq done t))
 	    ((not first)
-	     (setq unread-command-events (list char)
+	     ;; XEmacs change; event instead of char. 
+	     (setq unread-command-events (list event)
 		   done t))
 	    (t (setq code (char-to-int char)
 		     done t)))

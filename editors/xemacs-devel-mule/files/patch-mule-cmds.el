Index: lisp/mule/mule-cmds.el
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/lisp/mule/mule-cmds.el,v
retrieving revision 1.26
retrieving revision 1.27
diff -u -r1.26 -r1.27
--- lisp/mule/mule-cmds.el	2005/12/17 19:47:00	1.26
+++ lisp/mule/mule-cmds.el	2005/12/24 21:59:21	1.27
@@ -1341,12 +1341,19 @@
 	;;     locale but we should still use the right code page, etc.
 	(declare-fboundp (mswindows-set-current-locale userdef)))
       ;; Unix:
-      (let ((locstring (current-locale)))
-	;; assume C lib locale and LANG env var are set correctly.  use
-	;; them to find the langenv.
-	(setq langenv
-	      (and locstring (get-language-environment-from-locale
-			      locstring)))))
+      (let (locstring)
+	;; Init the POSIX locale from the environment--this calls the C
+	;; library's setlocale(3).
+	(set-current-locale "")
+	;; Can't let locstring be the result of (set-current-locale "")
+	;; because that can return a more detailed string than we know how
+	;; to handle.
+	(setq locstring (current-locale)
+	      ;; assume C lib locale and LANG env var are set correctly.
+	      ;; use them to find the langenv.
+	      langenv
+ 	      (and locstring (get-language-environment-from-locale
+ 			      locstring)))))
     ;; All systems:
     (unless langenv (setq langenv "English"))
     (setq current-language-environment langenv)

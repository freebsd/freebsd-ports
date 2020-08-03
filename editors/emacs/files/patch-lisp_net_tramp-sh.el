--- lisp/net/tramp-sh.el.orig	2019-07-25 19:41:28 UTC
+++ lisp/net/tramp-sh.el
@@ -4059,6 +4059,7 @@ process to set up.  VEC specifies the connection."
 
     ;; Disable echo expansion.
     (tramp-message vec 5 "Setting up remote shell environment")
+    (tramp-send-command vec "set +o vi +o emacs" t)
     (tramp-send-command
      vec "stty -inlcr -onlcr -echo kill '^U' erase '^H'" t)
     ;; Check whether the echo has really been disabled.  Some
@@ -4127,8 +4128,6 @@ process to set up.  VEC specifies the connection."
 	(set-process-coding-system proc cs-decode cs-encode)
 	(tramp-message
 	 vec 5 "Setting coding system to `%s' and `%s'" cs-decode cs-encode)))
-
-    (tramp-send-command vec "set +o vi +o emacs" t)
 
     ;; Check whether the remote host suffers from buggy
     ;; `send-process-string'.  This is known for FreeBSD (see comment

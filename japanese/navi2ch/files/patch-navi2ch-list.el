--- navi2ch-list.el.orig	2020-01-30 00:36:58 UTC
+++ navi2ch-list.el
@@ -94,7 +94,7 @@
      (nil " " navi2ch-list-board-name-face))))
 
 (defconst navi2ch-list-bbstable-default-url
-  "http://menu.2ch.net/bbsmenu.html")
+  "http://menu.5ch.net/bbsmenu.html")
 
 ;; add hook
 (add-hook 'navi2ch-save-status-hook 'navi2ch-list-save-info)
@@ -591,7 +591,7 @@ changed-list は '((board-id old-board new-board)
 	      (let (url board-id id u)
 		(when (and (not ignore)
 			   (string-match "href=\\(.+/\\([^/]+\\)/\\)" attr))
-		  (setq url (match-string 1 attr))
+		  (setq url (string-replace "https" "http" (match-string 1 attr)))
 		  (setq url (or (cdr (assoc
 				      url
 				      navi2ch-list-moved-board-alist))
@@ -624,6 +624,7 @@ changed-list は '((board-id old-board new-board)
 
 (defun navi2ch-list-valid-board (uri)
   (save-match-data
+    (setq uri (string-replace "https" "http" uri))
     (when (string-match "http://\\([^/]+\\)/\\([^/]+\\)/" uri)
       (let ((host (match-string 1 uri)))
 	(and (not (string-match navi2ch-list-invalid-host-regexp host))

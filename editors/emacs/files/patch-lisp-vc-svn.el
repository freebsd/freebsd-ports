
$FreeBSD$

--- lisp/vc-svn.el.orig
+++ lisp/vc-svn.el
@@ -71,9 +71,9 @@
   t			   ;`svn' doesn't support common args like -c or -b.
   "String or list of strings specifying extra switches for svn diff under VC.
 If nil, use the value of `vc-diff-switches' (or `diff-switches'),
-together with \"-x --diff-cmd=diff\" (since svn diff does not
-support the default \"-c\" value of `diff-switches').  If you
-want to force an empty list of arguments, use t."
+together with \"-x --diff-cmd=\"`diff-command' (since 'svn diff'
+does not support the default \"-c\" value of `diff-switches').
+If you want to force an empty list of arguments, use t."
   :type '(choice (const :tag "Unspecified" nil)
 		 (const :tag "None" t)
 		 (string :tag "Argument String")
@@ -83,9 +83,9 @@
   :version "22.1"
   :group 'vc)
 
-(defcustom vc-svn-header (or (cdr (assoc 'SVN vc-header-alist)) '("\$Id\$"))
+(defcustom vc-svn-header '("\$Id\$")
   "Header keywords to be inserted by `vc-insert-headers'."
-  :version "22.1"
+  :version "24.1"     ; no longer consult the obsolete vc-header-alist
   :type '(repeat string)
   :group 'vc)
 
@@ -117,17 +117,13 @@
 ;;;###autoload                                (getenv "SVN_ASP_DOT_NET_HACK"))
 ;;;###autoload                           "_svn")
 ;;;###autoload                          (t ".svn"))))
-;;;###autoload     (when (file-readable-p (expand-file-name
-;;;###autoload                             (concat admin-dir "/entries")
-;;;###autoload                             (file-name-directory f)))
+;;;###autoload     (when (vc-find-root f admin-dir)
 ;;;###autoload       (load "vc-svn")
 ;;;###autoload       (vc-svn-registered f))))
 
 (defun vc-svn-registered (file)
   "Check if FILE is SVN registered."
-  (when (file-readable-p (expand-file-name (concat vc-svn-admin-directory
-						   "/entries")
-					   (file-name-directory file)))
+  (when (vc-svn-root file)
     (with-temp-buffer
       (cd (file-name-directory file))
       (let* (process-file-side-effects
@@ -170,15 +166,21 @@
                      (?? . unregistered)
                      ;; This is what vc-svn-parse-status does.
                      (?~ . edited)))
-	(re (if remote "^\\(.\\)......? \\([ *]\\) +\\(?:[-0-9]+\\)?   \\(.*\\)$"
-	      ;; Subexp 2 is a dummy in this case, so the numbers match.
-	      "^\\(.\\)....\\(.\\) \\(.*\\)$"))
+	(re (if remote "^\\(.\\)\\(.\\).....? \\([ *]\\) +\\(?:[-0-9]+\\)?   \\(.*\\)$"
+	      ;; Subexp 3 is a dummy in this case, so the numbers match.
+	      "^\\(.\\)\\(.\\)...\\(.\\) \\(.*\\)$"))
        result)
     (goto-char (point-min))
     (while (re-search-forward re nil t)
       (let ((state (cdr (assq (aref (match-string 1) 0) state-map)))
-	    (filename (match-string 3)))
-	(and remote (string-equal (match-string 2) "*")
+            (propstat (cdr (assq (aref (match-string 2) 0) state-map)))
+            (filename (if (memq system-type '(windows-nt ms-dos))
+                          (replace-regexp-in-string "\\\\" "/" (match-string 4))
+                        (match-string 4))))
+        (and (memq propstat '(conflict edited))
+             (not (eq state 'conflict)) ; conflict always wins
+             (setq state propstat))
+	(and remote (string-equal (match-string 3) "*")
 	     ;; FIXME are there other possible combinations?
 	     (cond ((eq state 'edited) (setq state 'needs-merge))
 		   ((not state) (setq state 'needs-update))))
@@ -271,18 +273,16 @@
 to the SVN command."
   (apply 'vc-svn-command nil 0 files "add" (vc-switches 'SVN 'register)))
 
-(defun vc-svn-responsible-p (file)
-  "Return non-nil if SVN thinks it is responsible for FILE."
-  (file-directory-p (expand-file-name vc-svn-admin-directory
-				      (if (file-directory-p file)
-					  file
-					(file-name-directory file)))))
+(defun vc-svn-root (file)
+  (vc-find-root file vc-svn-admin-directory))
 
-(defalias 'vc-svn-could-register 'vc-svn-responsible-p
+(defalias 'vc-svn-responsible-p 'vc-svn-root)
+
+(defalias 'vc-svn-could-register 'vc-svn-root
   "Return non-nil if FILE could be registered in SVN.
 This is only possible if SVN is responsible for FILE's directory.")
 
-(defun vc-svn-checkin (files rev comment)
+(defun vc-svn-checkin (files rev comment &optional extra-args-ignored)
   "SVN-specific version of `vc-backend-checkin'."
   (if rev (error "Committing to a specific revision is unsupported in SVN"))
   (let ((status (apply
@@ -518,7 +518,7 @@
   (let* ((switches
 	    (if vc-svn-diff-switches
 		(vc-switches 'SVN 'diff)
-	      (list "--diff-cmd=diff" "-x"
+	      (list (concat "--diff-cmd=" diff-command) "-x"
 		    (mapconcat 'identity (vc-switches nil 'diff) " "))))
 	   (async (and (not vc-disable-async-diff)
                        (vc-stay-local-p files 'SVN)
@@ -590,20 +590,10 @@
 
 (defun vc-svn-repository-hostname (dirname)
   (with-temp-buffer
-    (let ((coding-system-for-read
-	   (or file-name-coding-system
-	       default-file-name-coding-system)))
-      (vc-insert-file (expand-file-name (concat vc-svn-admin-directory
-						"/entries")
-					dirname)))
+    (let (process-file-side-effects)
+      (vc-svn-command t t dirname "info" "--xml"))
     (goto-char (point-min))
-    (when (re-search-forward
-	   ;; Old `svn' used name="svn:this_dir", newer use just name="".
-	   (concat "name=\"\\(?:svn:this_dir\\)?\"[\n\t ]*"
-		   "\\(?:[-a-z]+=\"[^\"]*\"[\n\t ]*\\)*?"
-		   "url=\"\\(?1:[^\"]+\\)\""
-                   ;; Yet newer ones don't use XML any more.
-                   "\\|^\ndir\n[0-9]+\n\\(?1:.*\\)") nil t)
+    (when (re-search-forward "<url>\\(.*\\)</url>" nil t)
       ;; This is not a hostname but a URL.  This may actually be considered
       ;; as a feature since it allows vc-svn-stay-local to specify different
       ;; behavior for different modules on the same server.
@@ -642,7 +632,7 @@
   "Parse output of \"svn status\" command in the current buffer.
 Set file properties accordingly.  Unless FILENAME is non-nil, parse only
 information about FILENAME and return its status."
-  (let (file status)
+  (let (file status propstat)
     (goto-char (point-min))
     (while (re-search-forward
             ;; Ignore the files with status X.
@@ -652,7 +642,9 @@
       (setq file (or filename
                      (expand-file-name
                       (buffer-substring (point) (line-end-position)))))
-      (setq status (char-after (line-beginning-position)))
+      (setq status (char-after (line-beginning-position))
+            ;; Status of the item's properties ([ MC]).
+            propstat (char-after (1+ (line-beginning-position))))
       (if (eq status ??)
 	  (vc-file-setprop file 'vc-state 'unregistered)
 	;; Use the last-modified revision, so that searching in vc-print-log
@@ -663,7 +655,7 @@
 	(vc-file-setprop
 	 file 'vc-state
 	 (cond
-	  ((eq status ?\ )
+	  ((and (eq status ?\ ) (eq propstat ?\ ))
 	   (if (eq (char-after (match-beginning 1)) ?*)
 	       'needs-update
              (vc-file-setprop file 'vc-checkout-time
@@ -674,9 +666,11 @@
 	   (vc-file-setprop file 'vc-working-revision "0")
 	   (vc-file-setprop file 'vc-checkout-time 0)
 	   'added)
-	  ((eq status ?C)
+	  ;; Conflict in contents or properties.
+	  ((or (eq status ?C) (eq propstat ?C))
 	   (vc-file-setprop file 'vc-state 'conflict))
-	  ((eq status '?M)
+	  ;; Modified contents or properties.
+	  ((or (eq status ?M) (eq propstat ?M))
 	   (if (eq (char-after (match-beginning 1)) ?*)
 	       'needs-merge
 	     'edited))
@@ -743,5 +737,4 @@
 
 (provide 'vc-svn)
 
-;; arch-tag: 02f10c68-2b4d-453a-90fc-1eee6cfb268d
 ;;; vc-svn.el ends here

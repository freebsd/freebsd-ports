--- gnuserv-compat.el.orig	Mon Feb 12 09:13:19 2001
+++ gnuserv-compat.el	Fri May 23 08:10:39 2003
@@ -1,10 +1,10 @@
 ;; gnuserv-compat.el - Help GNU XEmacs gnuserv.el work under GNU Emacs.
-;; Copyright (C) 1998, 1999, 2000 Martin Schwenke
+;; Copyright (C) 1998, 1999, 2000, 2003 Martin Schwenke
 ;;
 ;; Author: Martin Schwenke <martin@meltin.net>
 ;; Maintainer: Martin Schwenke <martin@meltin.net>
 ;; Created: 20 November 1998
-;; $Id: gnuserv-compat.el,v 1.7 2001/02/12 00:13:19 martin Exp $
+;; $Id: gnuserv-compat.el,v 1.10 2003/05/09 01:26:42 martins Exp $
 ;; Keywords: gnuserv
 
 ;; This program is free software; you can redistribute it and/or modify
@@ -26,7 +26,7 @@
 
 ;;; Commentary:
 ;;
-;; Under non-XEmacs (tested 19.34 <= ... <= 20.7)
+;; Under non-XEmacs (tested 20.7, 21.x)
 ;;
 ;;   (autoload 'gnuserv-start "gnuserv-compat"
 ;;             "Allow this Emacs process to be a server for client processes."
@@ -51,40 +51,50 @@
 
 (require 'cl)
 
-(unless (fboundp 'define-obsolete-variable-alias)
-  (defalias 'define-obsolete-variable-alias 'make-obsolete-variable))
+(eval-and-compile
+  (unless (fboundp 'define-obsolete-variable-alias)
+    (defalias 'define-obsolete-variable-alias 'make-obsolete-variable))
 
-(unless (fboundp 'functionp)
-  (defun functionp (object)
-    "Non-nil if OBJECT is a type of object that can be called as a function."
-    (or (subrp object) (byte-code-function-p object)
-	(eq (car-safe object) 'lambda)
-	(and (symbolp object) (fboundp object)))))
-
-;;; temporary-file-directory not available in 19.34
-(unless (boundp 'temporary-file-directory)
-  (defvar temporary-file-directory
-    (cond
-     ((getenv "TMPDIR"))
-     (t "/tmp"))))
-
-(unless (fboundp 'temp-directory)
-  (defun temp-directory ()
-    "Return the pathname to the directory to use for temporary files.
+  (unless (fboundp 'functionp)
+    (defun functionp (object)
+      "Non-nil if OBJECT is a type of object that can be called as a function."
+      (or (subrp object) (byte-code-function-p object)
+	  (eq (car-safe object) 'lambda)
+	  (and (symbolp object) (fboundp object)))))
+  
+  ;; add-minor-mode not available in 20.7
+  (unless (fboundp 'add-minor-mode)
+    (defun add-minor-mode (toggle name)
+      "Register a new minor mode."
+      (pushnew (list toggle name)
+	       minor-mode-alist
+	       :test 'equal)))
+  
+  ;; temporary-file-directory not available in 19.34
+  (unless (boundp 'temporary-file-directory)
+    (defvar temporary-file-directory
+      (cond
+       ((getenv "TMPDIR"))
+       (t "/tmp"))))
+  
+  (unless (fboundp 'temp-directory)
+    (defun temp-directory ()
+      "Return the pathname to the directory to use for temporary files.
 On NT/MSDOS, this is obtained from the TEMP or TMP environment variables,
 defaulting to the value of `temporary-file-directory' if they are both
 undefined.  On Unix it is obtained from TMPDIR, with the value of
 `temporary-file-directory' as the default."
-
-    (if	(eq system-type 'windows-nt)
+      
+      (if	(eq system-type 'windows-nt)
+	  (cond
+	   ((getenv "TEMP"))
+	   ((getenv "TMP"))
+	   (t (directory-file-name temporary-file-directory)))
 	(cond
-	 ((getenv "TEMP"))
-	 ((getenv "TMP"))
-	 (t (directory-file-name temporary-file-directory)))
-      (cond
-	  ((getenv "TMPDIR"))
-	  (t (directory-file-name temporary-file-directory))))))
-
+	 ((getenv "TMPDIR"))
+	 (t (directory-file-name temporary-file-directory))))))
+  ) ;; eval-and-compile
+  
 
 ;; If we're not running XEmacs then advise `make-frame',
 ;; `delete-frame' and `filtered-frame-list' to handle some device
@@ -147,7 +157,7 @@
   (defalias 'device-list 'frame-list)
   (defalias 'selected-device 'selected-frame)
   (defun device-frame-list (&optional device)
-    (list 
+    (list
      (if device
 	device
        (selected-frame)))))
@@ -182,7 +192,7 @@
     ;; We have the old custom-library, hack around it!
     (defmacro defgroup (&rest args)
       nil)
-    (defmacro defcustom (var value doc &rest args) 
+    (defmacro defcustom (var value doc &rest args)
       (` (defvar (, var) (, value) (, doc))))
     (defmacro defface (var value doc &rest args)
       (` (make-face (, var))))

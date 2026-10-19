--- src/unix/emacs/mozc.el.orig	2026-10-16 12:33:33 UTC
+++ src/unix/emacs/mozc.el
@@ -1,3 +1,4 @@
+;; -*- lexical-binding: nil; -*-
 ;;; mozc.el --- minor mode to input Japanese with Mozc
 
 ;; Copyright 2010-2021, Google Inc. All rights reserved.
@@ -1551,7 +1552,7 @@ Return the new value of `mozc-session-seq'."
 
 ;;;; Communication with Mozc server through the helper process
 
-(defvar mozc-helper-program-name "mozc_emacs_helper"
+(defvar mozc-helper-program-name "%%LOCALBASE%%/libexec/mozc_emacs_helper"
   "Helper program's name or path to the helper program.
 The helper program helps Emacs communicate with Mozc server,
 which doesn't understand S-expression.")

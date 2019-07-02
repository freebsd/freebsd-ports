--- schematic/scheme/gschem/action.scm.orig	2018-12-11 19:24:41 UTC
+++ schematic/scheme/gschem/action.scm
@@ -1,6 +1,7 @@
 ;; Lepton EDA Schematic Capture
 ;; Scheme API
 ;; Copyright (C) 2013 Peter Brett <peter@peter-b.co.uk>
+;; Copyright (C) 2017-2019 Lepton EDA Contributors
 ;;
 ;; This program is free software; you can redistribute it and/or modify
 ;; it under the terms of the GNU General Public License as published by
@@ -21,11 +22,10 @@
   #:use-module (gschem core gettext)
   #:use-module (gschem window)
   #:use-module (gschem hook)
+  #:use-module (geda log)
   #:use-module (ice-9 optargs)
   #:export-syntax (define-action))
 
-(or (defined? 'define-syntax)
-    (use-modules (ice-9 syncase)))
 
 (define last-action (make-fluid))
 (define current-action-position (make-fluid))
@@ -33,18 +33,25 @@
 ;; Define an eval-in-currentmodule procedure
 (define (eval-cm expr) (eval expr (current-module)))
 
-;; Evaluates a gschem action.  A gschem action is expected to be a
+;; Evaluates a lepton-schematic action.  An action is expected to be a
 ;; symbol naming a thunk variable in the current module.
 ;;
 ;; The special-case symbol repeat-last-command causes the last action
 ;; executed to be repeated.
 (define-public (eval-action! action)
   (define (invalid-action-error)
-    (error (_ "~S is not a valid gschem action.") action))
+    (log! 'warning (_ "[~A] is not a valid lepton-schematic action.") action))
+  (define (no-last-action-error)
+    (log! 'message (_ "There is no last action to repeat.")))
 
   (define (eval-action!/recursive a)
 
     (cond
+     ;; The action is #f when the user hits "." (repeat last action)
+     ;; and there is no last action to repeat.
+     ((eq? a #f)
+      (no-last-action-error))
+
      ;; Handle repeat-last-command
      ((equal? 'repeat-last-command a)
       ;; N.b. must call eval-action! rather than
@@ -107,29 +114,30 @@
   ;; The action is a magical procedure that does nothing but call
   ;; eval-action! *on itself*.  This allows you to invoke an action
   ;; just by calling it like a normal function.
-  (letrec ((action (lambda () (eval-action! action))))
+  (let ((unique-tag (list #f)))
+    (letrec ((action (case-lambda
+                       (() (eval-action! action))
+                       ((x) unique-tag))))
 
-    ;; The action data is stored in procedure properties -- most
-    ;; importantly, the actual thunk that the action wraps
-    (let ((sp! (lambda (k v) (set-procedure-property! action k v))))
-      (sp! 'gschem-cookie %cookie)
-      (sp! 'gschem-thunk thunk)
-      (sp! 'gschem-properties '()))
+      ;; The action data is stored in procedure properties -- most
+      ;; importantly, the actual thunk that the action wraps
+      (let ((sp! (lambda (k v) (set-procedure-property! action k v))))
+        (sp! 'gschem-cookie %cookie)
+        (sp! 'gschem-thunk thunk)
+        (sp! 'gschem-properties '()))
 
-    ;; Deal with any properties.  props should contain arguments in
-    ;; pairs, where the first element of each pair is a keyword naming
-    ;; a procedure property (e.g. #:icon) and the second element in
-    ;; the corresponding value (e.g. "insert-text").
-    (let loop ((lst props))
-      (and (< 1 (length lst))
-           (set-action-property! action
-                                 (keyword->symbol (list-ref lst 0))
-                                 (list-ref lst 1))
-           (loop (list-tail lst 2))))
-          
-          
+      ;; Deal with any properties.  props should contain arguments in
+      ;; pairs, where the first element of each pair is a keyword naming
+      ;; a procedure property (e.g. #:icon) and the second element in
+      ;; the corresponding value (e.g. "insert-text").
+      (let loop ((lst props))
+        (and (< 1 (length lst))
+             (set-action-property! action
+                                   (keyword->symbol (list-ref lst 0))
+                                   (list-ref lst 1))
+             (loop (list-tail lst 2))))
 
-    action))
+      action)))
 
 (define (action-thunk action)
   (procedure-property action 'gschem-thunk))

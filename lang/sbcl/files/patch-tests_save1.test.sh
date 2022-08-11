From 48d686f9718f98122547a9006c871cfcd50439ab Mon Sep 17 00:00:00 2001
From: Douglas Katzman <dougk@google.com>
Date: Sun, 31 Jul 2022 21:38:19 -0400
Subject: [PATCH] Accept that value-cell-value can move to R/O space

Fixes lp#1983218
--- tests/save1.test.sh.orig	2022-07-29 14:39:18 UTC
+++ tests/save1.test.sh
@@ -23,6 +23,11 @@ run_sbcl <<EOF
   ;; but maybe someone changed it :immobile, so bind it to be certain.
   (let (#+immobile-code (sb-c::*compile-to-memory-space* :dynamic))
      (defvar *afun* (compile nil '(lambda (x) (- (length x))))))
+  ;; test for lp#1983218 - a VALUE-CELL holding a readonly string could crash
+  (defun mkcell (x) (sb-sys:%primitive sb-vm::make-value-cell x nil))
+  (compile 'mkcell)
+  (defvar *cell* (mkcell (symbol-name '*print-base*)))
+  ;;
   (save-lisp-and-die "$tmpcore")
 EOF
 run_sbcl_with_core "$tmpcore" --noinform --no-userinit --no-sysinit --noprint \

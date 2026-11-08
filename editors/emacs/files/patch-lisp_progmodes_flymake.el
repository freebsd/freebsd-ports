From abc802ee2eb0b1663349ddf22a461f8e54a383fb Mon Sep 17 00:00:00 2001
From: Stefan Monnier <monnier@iro.umontreal.ca>
Date: Mon, 14 Sep 2026 11:30:39 +0100
Subject: [PATCH] flymake.el: Generalize trusted-content-p check to all
 backends

Minimal safe backport of this change:

    Author:     Stefan Monnier <monnier@iro.umontreal.ca>
    AuthorDate: Fri Sep 11 21:48:55 2026 -0400

      flymake.el: Generalize trusted-content-p check to all backends

      Rather than have each and every backend check
      'trusted-content-p' if it feels necessary, implement the check
      once and forall in flymake.el and provide a wat for backends to
      skip that test, so we replace an "opt-in" with an "opt-out"
      that's a bit more secure by design.

      * lisp/progmodes/elisp-mode.el (elisp-flymake-byte-compile):
      Move 'trusted-content-p' to flymake.el.
      * lisp/progmodes/flymake.el (flymake--run-backend):
      Move 'trusted-content-p' from elisp-mode.el.

      * lisp/progmodes/eglot.el (eglot-flymake-backend): Mark as safe.

* lisp/progmodes/flymake.el (flymake--run-backend): Copy
trusted-content-p check from elisp-mode.el.  Do not merge to
master.
---
 lisp/progmodes/flymake.el | 9 +++++++--
 1 file changed, 7 insertions(+), 2 deletions(-)

diff --git a/lisp/progmodes/flymake.el b/lisp/progmodes/flymake.el
index fff42696761..40761031dc2 100644
--- lisp/progmodes/flymake.el.orig	2026-08-17 17:42:57 UTC
+++ lisp/progmodes/flymake.el
@@ -1271,8 +1271,13 @@ with a report function."
             (flymake--state-disabled state) nil
             (flymake--state-reported-p state) nil))
     (condition-case-unless-debug err
-        (apply backend (flymake-make-report-fn backend run-token)
-               args)
+        (if (or (trusted-content-p) (function-get backend 'flymake-always-safe))
+            (apply backend (flymake-make-report-fn backend run-token)
+                   args)
+          (message "Disabling %S in %s (untrusted content)"
+                   backend (buffer-name))
+          (user-error "Disabling %S in %s (untrusted content)"
+                      backend (buffer-name)))
       (error
        (flymake--disable-backend backend err)))))
 

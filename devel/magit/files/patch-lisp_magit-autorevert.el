From 5183b8f0d42345432a560996e4f434d27452faa8 Mon Sep 17 00:00:00 2001
From: Jonas Bernoulli <jonas@bernoul.li>
Date: Fri, 24 Oct 2025 23:25:01 +0200
Subject: [PATCH] Support Emacs builds that feature
 custom-initialize-after-file-load

This will need more work.  We might be able to learn from that function
and simplify even when that is not available.  Also, while rudimentary
testing indicates this works as intended, this has to be studied in more
detail before we can be sure.  Do it now anyway, because the breakage
caused by not doing is definitely real.

See #5462.
---
 lisp/magit-autorevert.el | 17 ++++++++++-------
 1 file changed, 10 insertions(+), 7 deletions(-)

diff --git lisp/magit-autorevert.el lisp/magit-autorevert.el
index 90d83367..564b9c0d 100644
--- lisp/magit-autorevert.el
+++ lisp/magit-autorevert.el
@@ -166,13 +166,16 @@ and code surrounding the definition of this function."
              (format " (%.3fs, %s buffers checked)" elapsed
                      (length (buffer-list)))
            ""))))))
-(if after-init-time
-    ;; Since `after-init-hook' has already been
-    ;; run, turn the mode on or off right now.
-    (magit-auto-revert-mode--init-kludge)
-  ;; By the time the init file has been fully loaded the
-  ;; values of the relevant variables might have changed.
-  (add-hook 'after-init-hook #'magit-auto-revert-mode--init-kludge t))
+;; FIXME Suppressing this for recent 31.0.50 builds is not the
+;; final solution.
+(unless (fboundp 'custom-initialize-after-file-load)
+  (if after-init-time
+      ;; Since `after-init-hook' has already been
+      ;; run, turn the mode on or off right now.
+      (magit-auto-revert-mode--init-kludge)
+    ;; By the time the init file has been fully loaded the
+    ;; values of the relevant variables might have changed.
+    (add-hook 'after-init-hook #'magit-auto-revert-mode--init-kludge t)))
 
 (put 'magit-auto-revert-mode 'function-documentation
      "Toggle Magit Auto Revert mode.
-- 
2.51.2


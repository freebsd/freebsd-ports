
$FreeBSD: /tmp/pcvs/ports/editors/emacs22/files/Attic/patch-sources.el,v 1.1 2009-09-07 19:33:30 bsam Exp $

--- /dev/null
+++ sources.el
@@ -0,0 +1,4 @@
+;;; Path to Emacs C Sources.
+(when (string-match (regexp-quote "%%EMACS_VER%%") emacs-version)
+  (setq find-function-C-source-directory
+        "%%DATADIR%%/%%EMACS_VER%%/src"))

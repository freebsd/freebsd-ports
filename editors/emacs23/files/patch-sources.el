
$FreeBSD: /tmp/pcvs/ports/editors/emacs23/files/patch-sources.el,v 1.3 2009-12-20 20:19:17 bsam Exp $

--- /dev/null
+++ sources.el
@@ -0,0 +1,4 @@
+;;; Path to Emacs C Sources.
+(when (string-match (regexp-quote "%%EMACS_VER%%") emacs-version)
+  (setq find-function-C-source-directory
+        "%%DATADIR%%/%%EMACS_VER%%/src"))

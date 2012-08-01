
$FreeBSD$

--- /dev/null
+++ sources.el
@@ -0,0 +1,4 @@
+;;; Path to Emacs C Sources.
+(when (string-match (regexp-quote "%%EMACS_VER%%") emacs-version)
+  (setq find-function-C-source-directory
+        "%%DATADIR%%/%%EMACS_VER%%/src"))

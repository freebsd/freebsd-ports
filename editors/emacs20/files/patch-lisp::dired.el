--- lisp/dired.el.orig	Tue Nov 30 00:04:12 1999
+++ lisp/dired.el	Wed Dec  5 03:15:14 2001
@@ -1375,6 +1375,7 @@
          ;; weiand: changed: year potentially unaligned
 ;;old			  s "\\(" HH:MM "\\|" s yyyy "\\|" yyyy s "\\)"))
 			  s "\\(" HH:MM "\\|" s "?" yyyy "\\|" yyyy s "\\)"))
+	 (freebsd-ja (concat s mm "/" dd s "\\(" HH:MM "\\|" s yyyy "\\)"))
 	 (japanese (concat mm k s dd k s "\\(" s HH:MM "\\|" yyyy k "\\)")))
 	 ;; The "[0-9]" below requires the previous column to end in a digit.
 	 ;; This avoids recognizing `1 may 1997' as a date in the line:
@@ -1382,7 +1383,7 @@
 	 ;; The ".*" below finds the last match if there are multiple matches.
 	 ;; This avoids recognizing `jservice  10  1024' as a date in the line:
 	 ;; drwxr-xr-x  3 jservice  10  1024 Jul  2  1997 esg-host
-    (concat ".*[0-9]" s "\\(" western "\\|" japanese "\\)" s))
+    (concat ".*[0-9]" s "\\(" western "\\|" japanese "\\|" freebsd-ja "\\)" s))
   "Regular expression to match up to the file name in a directory listing.
 The default value is designed to recognize dates and times
 regardless of the language.")

--- lisp/dired.el.orig	Fri Feb  7 20:48:13 2003
+++ lisp/dired.el	Fri Mar 21 18:08:54 2003
@@ -1535,6 +1535,7 @@
 			          "\\|" yyyy s s "?"
 			          "\\|" s "?" yyyy
 			     "\\)"))
+	 (freebsd-ja (concat s mm "\\(" s "\\|/\\)" dd s "\\(" HH:MM "\\|" s yyyy "\\)"))
 	 (japanese
 	  (concat mm k "?" s dd k "?" s "+"
 		  "\\(" HH:MM "\\|" yyyy k "?" "\\)")))
@@ -1546,7 +1547,7 @@
 	 ;; This avoids recognizing `jservice  10  1024' as a date in the line:
 	 ;; drwxr-xr-x  3 jservice  10  1024 Jul  2  1997 esg-host
     (concat ".*[0-9][kKMGTPEZY]?" 
-	    s "\\(" western "\\|" japanese "\\|" iso "\\)" s))
+	    s "\\(" western "\\|" freebsd-ja "\\|" japanese "\\|" iso "\\)" s))
   "Regular expression to match up to the file name in a directory listing.
 The default value is designed to recognize dates and times
 regardless of the language.")

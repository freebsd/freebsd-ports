--- lisp/dired.el.orig	Sat Sep 22 01:41:58 2001
+++ lisp/dired.el	Wed Dec  5 20:06:04 2001
@@ -1532,6 +1532,7 @@
 			          "\\|" yyyy s s "?"
 			          "\\|" s "?" yyyy
 			     "\\)"))
+	 (freebsd-ja (concat s mm "/" dd s "\\(" HH:MM "\\|" s yyyy "\\)"))
 	 (japanese
 	  (concat mm k "?" s dd k "?" s "+"
 		  "\\(" HH:MM "\\|" yyyy k "?" "\\)")))
@@ -1543,7 +1544,7 @@
 	 ;; This avoids recognizing `jservice  10  1024' as a date in the line:
 	 ;; drwxr-xr-x  3 jservice  10  1024 Jul  2  1997 esg-host
     (concat ".*[0-9][kMGTPEZY]?" 
-	    s "\\(" western "\\|" japanese "\\|" iso "\\)" s))
+	    s "\\(" western "\\|" freebsd-ja "\\|" japanese "\\|" iso "\\)" s))
   "Regular expression to match up to the file name in a directory listing.
 The default value is designed to recognize dates and times
 regardless of the language.")

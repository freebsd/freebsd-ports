Index: navi2ch-net.el
===================================================================
RCS file: /cvsroot/navi2ch/navi2ch/navi2ch-net.el,v
retrieving revision 1.66
diff -u -u -r1.66 navi2ch-net.el
--- navi2ch-net.el	15 Dec 2002 04:23:00 -0000	1.66
+++ navi2ch-net.el	23 Mar 2003 09:16:29 -0000
@@ -34,6 +34,7 @@
 (defvar navi2ch-net-connection-name "navi2ch connection")
 (defvar navi2ch-net-user-agent "Monazilla/1.00 Navi2ch")
 (defvar navi2ch-net-setting-file-name "SETTING.TXT")
+(defvar navi2ch-net-last-date nil)
 (defvar navi2ch-net-last-url nil)
 (defvar navi2ch-net-process nil)
 (defvar navi2ch-net-last-host nil)
@@ -250,6 +251,9 @@
 	     (while (re-search-forward "^\\([^\r\n:]+\\): \\(.+\\)\r\n" end t)
 	       (setq list (cons (cons (match-string 1) (match-string 2))
 				list)))
+	     (let ((date (assoc-ignore-case "Date" list)))
+	       (when (and date (stringp (cdr date)))
+		 (setq navi2ch-net-last-date (cdr date))))
 	     (setq navi2ch-net-header (nreverse list))))))))
 
 (defun navi2ch-net-get-content-subr-with-temp-file (gzip-p start end)
@@ -378,6 +382,7 @@
 			 (cons "Pragma" "no-cache")
 		       (and time (cons "If-Modified-Since" time)))
 		     (and navi2ch-net-accept-gzip
+			  (not (assoc "Range" other-header))
 			  '("Accept-Encoding" . "gzip"))
 		     (and navi2ch-net-user-agent
 			  (cons "User-Agent" navi2ch-net-user-agent)))

Index: navi2ch-multibbs.el
===================================================================
RCS file: /cvsroot/navi2ch/navi2ch/navi2ch-multibbs.el,v
retrieving revision 1.20
diff -u -u -r1.20 navi2ch-multibbs.el
--- navi2ch-multibbs.el	15 Dec 2002 04:23:00 -0000	1.20
+++ navi2ch-multibbs.el	23 Mar 2003 09:16:07 -0000
@@ -32,6 +32,7 @@
 (defvar navi2ch-multibbs-ident
   "$Id: navi2ch-multibbs.el,v 1.20 2002/12/15 04:23:00 nanashi Exp $")
 
+(require 'navi2ch-http-date)
 (require 'navi2ch)
 
 (defvar navi2ch-multibbs-func-alist nil
@@ -221,6 +222,18 @@
 	       board 'article-to-url 'navi2ch-2ch-article-to-url)))
     (funcall func board article start end nofirst)))
 
+(defun navi2ch-multibbs-get-message-time-field ()
+  (if (stringp navi2ch-net-last-date)
+      (navi2ch-http-date-decode navi2ch-net-last-date)
+    (let* ((now (current-time))
+	   (lag 300)			; ずらす秒数
+	   (h (nth 0 now))
+	   (l (- (nth 1 now) lag)))
+      (when (< l 0)
+	(setq l (+ l 65536)
+	      h (- h 0)))
+      (cons h l))))
+
 (defun navi2ch-multibbs-send-message
   (from mail message subject board article)
   (let* ((bbstype      (navi2ch-multibbs-get-bbstype board))
@@ -236,12 +249,8 @@
 			 (string-match "\\([^/]+\\)/$" uri)
 			 (match-string 1 uri)))
 	 (key          (cdr (assq 'artid article)))
-	 (time         (mapconcat 'int-to-string
-				  (let ((time (current-time)))
-				    (navi2ch-bigint-add
-				     (navi2ch-bigint-multiply
-				      (nth 0 time) (expt 2 16)) (nth 1 time)))
-				  ""))
+	 (time         (format-time-string
+			"%s" (navi2ch-multibbs-get-message-time-field)))
 	 (navi2ch-net-http-proxy (and navi2ch-net-send-message-use-http-proxy
 				      navi2ch-net-http-proxy))
 	 (tries 2)	; 送信試行の最大回数

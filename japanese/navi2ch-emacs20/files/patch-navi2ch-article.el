--- navi2ch-article.el.orig	Wed Sep 10 21:54:33 2003
+++ navi2ch-article.el	Mon Dec  8 19:41:55 2003
@@ -1445,8 +1445,9 @@
   (cond ((string-match "\\([0-9]+\\)-\\([0-9]+\\)" str)
 	 (let* ((n1 (string-to-number (match-string 1 str)))
 		(n2 (string-to-number (match-string 2 str)))
-		(min (min n1 n2))
-		(i (max n1 n2))
+		(min (max (min n1 n2) 1))
+		(i (min (max n1 n2)
+			(1+ (length navi2ch-article-message-list))))
 		list)
 	   (while (>= i min)
 	     (push i list)

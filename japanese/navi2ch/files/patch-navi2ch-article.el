--- navi2ch-article.el.orig	2024-03-27 06:04:56 UTC
+++ navi2ch-article.el
@@ -289,9 +289,9 @@ last が最後からいくつ表示するか。
 	      (substring artid 0 3)
 	      "/" artid ".dat.gz"))
      ((= length 10)
-      (concat url "kako/"
-	      (substring artid 0 4) "/" (substring artid 0 5)
-	      "/" artid ".dat.gz"))
+	(concat url "oyster/"
+		(substring artid 0 4)
+		"/" artid ".dat"))
      (t
       nil))))
 

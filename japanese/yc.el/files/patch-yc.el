--- yc.el.orig	2018-06-04 13:46:33.083915000 +0900
+++ yc.el	2018-06-04 14:48:21.116298000 +0900
@@ -1736,6 +1736,7 @@
 				   (error nil))))
 	    (yc-eval-sexp (car expr)))))
       (setq files (cdr files)))
+    (message "")
     (if romkana-table
 	(setq yc-rH-conv-dic (yc-search-file-first-in-path
 			      romkana-table (list "." (getenv "HOME")
@@ -2071,7 +2072,7 @@
 ;; 文節を指定しない場合、現在の文節が対象となる
 ;; 読みを取得した文節はその読みをキャッシュする
 ;; cut が 非nil の場合、指定文節以降の読みを削除する
-(defun yc-yomi (&optional idx &optional cut)
+(defun yc-yomi (&optional idx cut)
   (if (integerp idx)
       (yc-put-bunsetsu-yomi idx (yc-get-bunsetsu-yomi idx cut) cut)
     (yc-put-bunsetsu-yomi yc-mark (yc-get-bunsetsu-yomi yc-mark cut) cut)))

--- yc.el.orig	2020-09-25 04:51:12 UTC
+++ yc.el
@@ -393,7 +393,9 @@ OBJ を返却する。"
 		       (error nil)))))))
   (when (processp yc-server)
     (put 'yc-server 'init nil)
-    (process-kill-without-query yc-server)
+    (if (boundp 'process-kill-without-query)
+	(process-kill-without-query yc-server)
+      (set-process-query-on-exit-flag yc-server nil))
     (when yc-debug
       (unwind-protect
 	  (progn
@@ -1736,6 +1738,7 @@ OBJ を返却する。"
 				   (error nil))))
 	    (yc-eval-sexp (car expr)))))
       (setq files (cdr files)))
+    (message "")
     (if romkana-table
 	(setq yc-rH-conv-dic (yc-search-file-first-in-path
 			      romkana-table (list "." (getenv "HOME")
@@ -2071,7 +2074,7 @@ OBJ を返却する。"
 ;; 文節を指定しない場合、現在の文節が対象となる
 ;; 読みを取得した文節はその読みをキャッシュする
 ;; cut が 非nil の場合、指定文節以降の読みを削除する
-(defun yc-yomi (&optional idx &optional cut)
+(defun yc-yomi (&optional idx cut)
   (if (integerp idx)
       (yc-put-bunsetsu-yomi idx (yc-get-bunsetsu-yomi idx cut) cut)
     (yc-put-bunsetsu-yomi yc-mark (yc-get-bunsetsu-yomi yc-mark cut) cut)))

--- yc.el.orig	2008-02-17 00:37:39.000000000 +0900
+++ yc.el	2008-02-17 00:38:16.000000000 +0900
@@ -393,7 +393,7 @@
 		       (error nil)))))))
   (when (processp yc-server)
     (put 'yc-server 'init nil)
-    (process-kill-without-query yc-server)
+    (set-process-query-on-exit-flag yc-server nil)
     (when yc-debug
       (unwind-protect
 	  (progn
@@ -4046,14 +4046,15 @@
  "japanese-yc" "Japanese" 'yc-activate
  "あ" "Romaji -> Hiragana -> Kanji&Kana"
  nil)
-(set-language-info "Japanese" 'input-method "japanese-yc")
-;(setq default-input-method "japanese-yc"))
+(defun force-yc-input-mode ()
+  (set-language-info "Japanese" 'input-method "japanese-yc")
+  (setq default-input-method "japanese-yc"))
 
-;(yc-setup)
-;(when (and yc-connect-server-at-startup (yc-server-check))
-;  (yc-init)
-;  (force-yc-input-mode)
-;  )
+(yc-setup)
+(when (and yc-connect-server-at-startup (yc-server-check))
+  (yc-init)
+  (force-yc-input-mode)
+  )
 
 (defconst yc-version "5.0.0")
 (provide 'yc)

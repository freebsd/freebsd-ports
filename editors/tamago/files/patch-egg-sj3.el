--- egg/sj3.el.orig	2015-01-31 19:23:34.000000000 +0900
+++ egg/sj3.el	2015-02-02 00:33:30.000000000 +0900
@@ -146,11 +146,10 @@
 	(setq proc (open-network-stream "SJ3" buf hostname sj3-server-port))
       ((error quit)
        (egg-error "failed to connect sj3 server")))
-    (process-kill-without-query proc)
+    (set-process-query-on-exit-flag proc nil)
     (set-process-coding-system proc 'binary 'binary)
     (set-marker-insertion-type (process-mark proc) t)
-    (save-excursion
-      (set-buffer buf)
+    (with-current-buffer buf
       (erase-buffer)
       (buffer-disable-undo)
       (set-buffer-multibyte nil))
@@ -177,8 +176,7 @@
 ;;   (let* ((buf (generate-new-buffer " *SJ3*"))
 ;; 	 (msg-form "SJ3: connecting to sj3serv at %s...")
 ;; 	 hostname proc result msg)
-;;     (save-excursion
-;;       (set-buffer buf)
+;;     (with-current-buffer buf
 ;;       (erase-buffer)
 ;;       (buffer-disable-undo)
 ;;       (setq enable-multibyte-characters nil))

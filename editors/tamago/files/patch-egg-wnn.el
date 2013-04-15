--- egg/wnn.el.2	2010-03-02 10:35:45.000000000 +0900
+++ egg/wnn.el	2010-03-02 11:54:30.000000000 +0900
@@ -82,6 +82,10 @@
 			     (const wnn-uniq)
 			     (const wnn-uniq-kanji)))
 
+(defcustom egg-wnn-helper-path "egg-helper"
+  "path of wnn unix domain connection helper program"
+  :group 'wnn :type 'file)
+
 (defcustom wnn-jserver nil
   "jserver hostname list.  Use N-th port, if hostname is followed
 by ':' and digit N."
@@ -99,11 +103,21 @@
  by ':' and digit N."
   :group 'wnn :type '(repeat string))
 
+(setq wnn-jserverenv "JSERVER")
+(setq wnn-cserverenv "CSERVER")
+(setq wnn-tserverenv "TSERVER")
+(setq wnn-kserverenv "KSERVER")
+
 (defcustom wnn-jport 22273 "jserver port number" :group 'wnn :type 'integer)
 (defcustom wnn-cport 22289 "cserver port number" :group 'wnn :type 'integer)
 (defcustom wnn-tport 22321 "tserver port number" :group 'wnn :type 'integer)
 (defcustom wnn-kport 22305 "kserver port number" :group 'wnn :type 'integer)
 
+(defcustom wnn-judpath "/tmp/jd_sockV4" "jserver unix domain socket name" :group 'wnn :type 'string)
+(defcustom wnn-cudpath "/tmp/cd_sockV4" "cserver unix domain socket name" :group 'wnn :type 'string)
+(defcustom wnn-tudpath "/tmp/td_sockV4" "tserver unix domain socket name" :group 'wnn :type 'string)
+(defcustom wnn-kudpath "/tmp/kd_sockV4" "kserver unix domain socket name" :group 'wnn :type 'string)
+
 (defmacro wnn-backend-plist ()
   ''(egg-initialize-backend        wnn-init
      egg-start-conversion          wnn-start-conversion
@@ -559,11 +573,11 @@
 	  bunsetsu))
 
 (defvar wnn-server-info-list
-  ;; language    server  port      hostname    proc   coding-system
-  '((Japanese    jserver wnn-jport wnn-jserver "Wnn"  (fixed-euc-jp    fixed-euc-jp))
-    (Chinese-GB  cserver wnn-cport wnn-cserver "cWnn" (fixed-euc-py-cn fixed-euc-zy-cn))
-    (Chinese-CNS tserver wnn-tport wnn-tserver "tWnn" (fixed-euc-py-tw fixed-euc-zy-tw))
-    (Korean      kserver wnn-kport wnn-kserver "kWnn" (fixed-euc-kr    fixed-euc-kr))))
+  ;; language    server  port      hostname    unixdomain  serverenv      proc   coding-system
+  '((Japanese    jserver wnn-jport wnn-jserver wnn-judpath wnn-jserverenv "Wnn"  (fixed-euc-jp    fixed-euc-jp))
+    (Chinese-GB  cserver wnn-cport wnn-cserver wnn-cudpath wnn-cserverenv "cWnn" (fixed-euc-py-cn fixed-euc-zy-cn))
+    (Chinese-CNS tserver wnn-tport wnn-tserver wnn-tudpath wnn-tserverenv "tWnn" (fixed-euc-py-tw fixed-euc-zy-tw))
+    (Korean      kserver wnn-kport wnn-kserver wnn-kudpath wnn-kserverenv "kWnn" (fixed-euc-kr    fixed-euc-kr))))
 
 (defsubst wnn-server-get-info (lang)
   (or (assq lang wnn-server-info-list)
@@ -577,12 +591,16 @@
   (symbol-value (nth 2 info)))
 (defsubst wnn-server-hostname (info)
   (symbol-value (nth 3 info)))
+(defsubst wnn-server-udpath-name (info)
+  (symbol-value (nth 4 info)))
+(defsubst wnn-server-env-name (info)
+  (symbol-value (nth 5 info)))
 (defsubst wnn-server-proc-name (info)
-  (nth 4 info))
+  (nth 6 info))
 (defsubst wnn-server-buffer-name (info)
   (concat " *" (wnn-server-proc-name info) "*"))
 (defsubst wnn-server-coding-system (info)
-  (nth 5 info))
+  (nth 7 info))
 
 (defconst wnn-accept-charset-alist
   '((Chinese-CNS ascii chinese-sisheng chinese-cns11643-1 chinese-cns11643-2)))
@@ -1209,9 +1227,11 @@
 	(port (wnn-server-port server-info))
 	(hostname-list (wnn-server-hostname server-info))
 	(proc-name (wnn-server-proc-name server-info))
+	(udpath (wnn-server-udpath-name server-info))
+	(serverenv (wnn-server-env-name server-info))
 	(msg-form "Wnn: connecting to %S at %s...")
 	(user-name (user-login-name))
-	buf hostname myname port-off proc result msg)
+	buf hostname port-off proc result msg)
     (unwind-protect
 	(progn
 	  (setq buf (generate-new-buffer (wnn-server-buffer-name server-info)))
@@ -1225,13 +1245,24 @@
 	      (setq hostname-list (list hostname-list)))
 	  (while (and hostname-list (null proc))
 	    (setq hostname (or (car hostname-list) "")
-		  hostname-list (cdr hostname-list)
-		  myname (if (equal hostname "") "unix" wnn-system-name))
-	    (if (null (string-match ":" hostname))
-		(setq port-off 0)
-	      (setq port-off (string-to-int (substring hostname (match-end 0)))
-		    hostname (substring hostname 0 (match-beginning 0))))
-	    (and (equal hostname "") (setq hostname "localhost"))
+		hostname-list (cdr hostname-list))
+	    (if (or (and (getenv serverenv)
+			 (string-match "^unix$" (getenv serverenv)))
+		    (and (null (getenv serverenv))
+			 (or (equal hostname "")
+			     (string-match "^unix$" hostname))))
+		(progn
+		  (setq hostname "unix"
+			family 'local
+			port udpath))
+	       (progn
+		(setq hostname (or (getenv serverenv) hostname "localhost"))
+		(if (null (string-match ":" hostname))
+		    (setq port-off 0)
+		  (setq port-off (string-to-number (substring hostname (match-end 0)))
+			hostname (substring hostname 0 (match-beginning 0))))
+		(setq family nil)))
+	    (setq host hostname)
 	    (let ((inhibit-quit save-inhibit-quit))
 	      (if (and msg
 		       (null (y-or-n-p (format "%s failed. Try to %s? "
@@ -1241,16 +1272,22 @@
 			      server-type hostname))
 	    (message "%s" msg)
 	    (let ((inhibit-quit save-inhibit-quit))
-	      (condition-case nil
-		  (setq proc (open-network-stream proc-name buf hostname
-						  (+ port port-off)))
-		((error quit))))
-	    (when proc
+             (if (fboundp 'make-network-process)
+                 (condition-case nil
+                     (setq proc (make-network-process :name proc-name :buffer buf :host host :service port :family family))
+                   ((error quit)))
+               (if (string-match "^unix$" hostname)
+                   (let ((process-connection-type nil))
+                     (setq proc (start-process proc-name buf egg-wnn-helper-path port)))
+                 (condition-case nil
+                     (setq proc (open-network-stream proc-name buf hostname port))
+                   (error quit)))))
+           (when (processp proc)
 	      (process-kill-without-query proc)
 	      (set-process-coding-system proc 'binary 'binary)
 	      (set-process-sentinel proc 'wnn-comm-sentinel)
 	      (set-marker-insertion-type (process-mark proc) t)
-	      (setq result (wnnrpc-open proc myname user-name))
+	      (setq result (wnnrpc-open proc host user-name))
 	      (when (numberp result)
 		(delete-process proc)
 		(setq proc nil))))

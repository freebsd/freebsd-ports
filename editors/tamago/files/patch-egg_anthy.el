From 235a48d7ba09ac37408790ed4eef511980b4393b Mon Sep 17 00:00:00 2001
From: Yasuhiro Kimura <yasu@utahime.org>
Date: Sun, 6 Jul 2025 18:28:29 +0900
Subject: [PATCH] Add support of Anthy Unicode

---
 egg/anthy.el | 24 ++++++++++++++++--------
 1 file changed, 16 insertions(+), 8 deletions(-)

diff --git egg/anthy.el egg/anthy.el
index 404a287..24dcf74 100644
--- egg/anthy.el
+++ egg/anthy.el
@@ -38,6 +38,12 @@
   "Anthy interface for Tamago 4."
   :group 'egg)
 
+(defcustom anthy-egg-use-anthy-unicode nil
+  "*Use Anthy Unicode as backend."
+  :group 'anthy-egg
+  :type '(choise (const :tag "Use Anthy Unicode as backend" t)
+		  (const :tag "Not use Anthy Unicode as backend" nil)))
+
 (defcustom anthy-egg-use-utf8 nil
   "*Use UTF-8 for anthy-agent and anthy-dic-tool."
   :group 'anthy-egg
@@ -138,12 +144,13 @@
 (defun anthy-egg-new-environment ()
   (if (null anthy-egg-proc)
       (let ((buf (get-buffer-create anthy-egg-agent-buffer-name))
-	    (cs (if anthy-egg-use-utf8 'utf-8-dos 'euc-japan-dos))
+	    (cs (if (or anthy-egg-use-anthy-unicode anthy-egg-use-utf8)
+		    'utf-8-dos 'euc-japan-dos))
 	    (process-connection-type nil)) ; avoid using pty
 	(setq anthy-egg-proc
 	      (apply 'start-process "anthy-egg-agent" buf
-		     "anthy-agent"
-		     (if anthy-egg-use-utf8
+		     (if anthy-egg-use-anthy-unicode "anthy-agent-unicode" "anthy-agent")
+		     (if (and (not anthy-egg-use-anthy-unicode) anthy-egg-use-utf8)
 			 '("--egg" "--utf8")
 		       '("--egg"))))
 	(set-process-query-on-exit-flag anthy-egg-proc nil)
@@ -182,7 +189,8 @@
 (make-variable-buffer-local 'anthy-egg-force-anthy)
 
 (defmacro anthy-egg-utf8-p ()
-  `(and anthy-egg-use-utf8
+  `(and anthy-egg-use-anthy-unicode
+	anthy-egg-use-utf8
 	(not anthy-egg-use-chinese-korean-server)
 	(or (equal (egg-get-conversion-backend 'Japanese 0 nil)
 		   '(0 (anthy-egg-conversion-backend)))
@@ -383,7 +391,6 @@ Return the list of bunsetsu."
   "*Anthy の動詞活用型.")
 
 
-(defvar anthy-egg-dic-util-command "anthy-dic-tool")
 (defvar anthy-egg-dic-buffer-name " *anthy-egg-dic*")
 
 (defun anthy-egg-add-word-compose-paramlist (param)
@@ -401,12 +408,13 @@ Return the list of bunsetsu."
 
 (defun anthy-egg-add-word (yomi freq word paramlist)
   (let ((buf (get-buffer-create anthy-egg-dic-buffer-name))
-	(cs (if anthy-egg-use-utf8 'utf-8-unix 'euc-japan-unix))
+	(cs (if (or anthy-egg-use-anthy-unicode anthy-egg-use-utf8)
+		'utf-8-unix 'euc-japan-unix))
 	proc)
     (with-current-buffer buf
       (setq proc (apply 'start-process "anthy-egg-dic" buf
-			anthy-egg-dic-util-command
-			(if anthy-egg-use-utf8
+			(if anthy-egg-use-anthy-unicode "anthy-dic-tool-unicode" "anthy-dic-tool")
+			(if (and (not anthy-egg-use-anthy-unicode) anthy-egg-use-utf8)
 			    '("--append" "--utf8")
 			  '("--append"))))
       (when proc
-- 
2.50.0


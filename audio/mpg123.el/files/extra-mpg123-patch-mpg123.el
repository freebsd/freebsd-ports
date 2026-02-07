--- mpg123.el.orig	2024-03-27 15:59:38 UTC
+++ mpg123.el
@@ -608,12 +608,7 @@
 
 ;;; Code:
 
-(defvar mpg123-use-mplayer
-  (or (and (fboundp 'executable-find)
-	     (executable-find "mplayer"))
-	(and (featurep 'xemacs)
-	     (fboundp 'exec-installed-p)
-	     (exec-installed-p "mplayer")))
+(defvar mpg123-use-mplayer nil
   "*Use mplayer command instead of mp123/ogg123.")
 ;; Linux users still using OSS rather than ALSA may wish to use
 ;; (setq mpg123-mixer-type 'aumix) before loading mpg123.el

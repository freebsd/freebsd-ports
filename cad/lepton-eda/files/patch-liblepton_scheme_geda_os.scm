--- liblepton/scheme/geda/os.scm.orig	2019-10-03 20:45:55 UTC
+++ liblepton/scheme/geda/os.scm
@@ -49,6 +49,7 @@
 (define-public sys-config-dirs %sys-config-dirs)
 (define-public user-data-dir %user-data-dir)
 (define-public user-config-dir %user-config-dir)
+(define-public user-cache-dir %user-cache-dir)
 
 (define-public expand-env-variables
   ;; Only compile regular expression once

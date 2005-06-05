--- scm/skk-custom.scm.orig	Tue May 17 19:06:47 2005
+++ scm/skk-custom.scm	Tue May 17 19:13:48 2005
@@ -168,8 +168,7 @@
 ;; dictionary
 ;;
 
-(define-custom 'skk-dic-file-name (string-append (sys-datadir)
-						 "/skk/SKK-JISYO.L")
+(define-custom 'skk-dic-file-name "%%LOCALBASE%%/share/skk/SKK-JISYO.L"
   '(skk dictionary)
   '(pathname)
   (_ "Dictionary file")

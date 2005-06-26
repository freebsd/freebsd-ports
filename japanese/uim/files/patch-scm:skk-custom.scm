--- scm/skk-custom.scm.orig	Tue Jun 14 05:46:11 2005
+++ scm/skk-custom.scm	Mon Jun 27 02:29:34 2005
@@ -338,8 +338,7 @@
 		 (lambda ()
 		   skk-use-skkserv?))
 
-(define-custom 'skk-dic-file-name (string-append (sys-datadir)
-						 "/skk/SKK-JISYO.L")
+(define-custom 'skk-dic-file-name "%%LOCALBASE%%/share/skk/SKK-JISYO.L"
   '(skk-dict)
   '(pathname)
   (_ "Dictionary file")

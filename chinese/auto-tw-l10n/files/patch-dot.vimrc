--- dot.vimrc.orig	2015-06-08 09:31:24.632410000 +0800
+++ dot.vimrc	2015-06-08 09:32:26.848032000 +0800
@@ -84,21 +84,11 @@
 "-------------------------------------
 " Vim locale
 "-------------------------------------
-"set enc=big5
-"set fileencoding=big5
+set enc=utf-8
+set fileencoding=utf-8
 set hls                
 set sw=2        
 set background=dark
-set fileencoding=big5
-
-if exists("&encoding")
-    set fileencodings=ucs-bom,utf-8,japan,big5,prc
-    if has("gui_running")
-	set encoding=utf-8
-    else
-	set encoding=big5
-    endif
-endif
 
 set langmenu=none
 syntax on

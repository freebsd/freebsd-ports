--- navi2ch-vars.el.orig	2020-01-30 00:36:58 UTC
+++ navi2ch-vars.el
@@ -255,7 +255,7 @@ nil $B$J$i$P<jF0$G99?7$7$J$$$+$.$j<h$j$K$$$+$J$$!#(B
 
 (defcustom navi2ch-list-valid-host-regexp
   (concat "\\("
-	  (regexp-opt '(".2ch.net" ".bbspink.com" ".machibbs.com" ".machi.to"))
+	  (regexp-opt '(".5ch.io" ".5ch.net" ".bbspink.com" ".2ch.net" ".2ch.sc"))
 	  "\\)\\'")
   "*$B#2$A$c$s$M$k$NHD$H$_$J$9%[%9%H$N@55,I=8=!#(B"
   :type 'regexp
@@ -2009,8 +2009,8 @@ Navi2ch$B%+%F%4%j$K!VAw?.95$(!WHD$,<+F0E*$KDI2C$5$l$^
 
 ;; net variables
 (defcustom navi2ch-net-http-proxy
-  (if (string= (getenv "HTTP_PROXY") "")
-      nil
+  (if (string= (or (getenv "HTTP_PROXY") "") "")
+      "127.0.0.1:9080"
     (getenv "HTTP_PROXY"))
   "*HTTP $B%W%m%-%7$N(B URL$B!#(B"
   :type '(choice (string :tag "$B%W%m%-%7$r;XDj(B")

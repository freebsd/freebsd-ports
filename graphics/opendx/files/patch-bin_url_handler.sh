--- bin/url_handler.sh.orig	2002-04-10 23:32:54 UTC
+++ bin/url_handler.sh
@@ -39,8 +39,8 @@ case $method in
 		if [ $use_xbrowser = n ]; then
 			lynx "$url" 
 		else
-			netscape -remote "openURL($url)" 2> /dev/null || \
-			(netscape "$url" &)
+			$BROWSER -remote "openURL($url)" 2> /dev/null || \
+			($BROWSER "$url" &)
                 fi
 		;;
 esac

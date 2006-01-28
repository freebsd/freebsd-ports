--- ./bin/url_handler.sh.orig	Thu Apr 11 01:32:54 2002
+++ ./bin/url_handler.sh	Sat Jan 28 15:27:41 2006
@@ -39,8 +39,8 @@
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

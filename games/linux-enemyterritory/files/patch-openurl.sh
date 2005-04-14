--- openurl.sh.orig	Fri Mar 25 07:27:39 2005
+++ openurl.sh	Fri Mar 25 07:41:06 2005
@@ -1,14 +1,12 @@
 #!/bin/sh
 # use this script to customize the way the engine should open URLs
 
-for test_browser in mozilla netscape
-do
-  browser=`which $test_browser`
-  if [ "x$browser" != "x" ]
-  then
-    $browser -remote "openURL($1,new-window)" || $browser "$1"
-    exit
-  fi
-done
-
-xterm -e lynx "$1"
+if [ -n "$BROWSER" ]; then
+    exec $BROWSER "$1"
+else
+    for browser in gnome-open epiphany galeon firefox konqueror mozilla; do
+	if which $browser >/dev/null 2>&1; then
+	    exec $browser "$1"
+	fi
+    done
+fi

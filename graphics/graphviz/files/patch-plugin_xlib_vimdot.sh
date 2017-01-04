--- plugin/xlib/vimdot.sh.orig	2016-12-01 06:43:36.000000000 +0100
+++ plugin/xlib/vimdot.sh	2016-12-25 20:26:20.202321000 +0100
@@ -5,7 +5,7 @@
 
 # Try $EDITOR first, else try vim or vi
 editor="$EDITOR"
-[ -x "$editor" ] || editor="/usr/bin/vim"
+[ -x "$editor" ] || editor="/usr/local/bin/vim"
 [ -x "$editor" ] || editor="/usr/bin/vi"
 [ -x "$editor" ] || error "EDITOR not found or not executable";
 
@@ -25,7 +25,7 @@
 
 	vim [href="http://www.vim.org/"]
 	dot [href="http://www.graphviz.org/"]
-	vimdot [href="file:///usr/bin/vimdot"]
+	vimdot [href="file:///usr/local/bin/vimdot"]
 
 	{vim dot} -> vimdot
 }

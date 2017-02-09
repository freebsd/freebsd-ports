--- plugin/xlib/vimdot.sh.orig	2016-12-01 05:43:36 UTC
+++ plugin/xlib/vimdot.sh
@@ -5,7 +5,7 @@ error() { echo "$0: $*" >&2; exit 1; }
 
 # Try $EDITOR first, else try vim or vi
 editor="$EDITOR"
-[ -x "$editor" ] || editor="/usr/bin/vim"
+[ -x "$editor" ] || editor="/usr/local/bin/vim"
 [ -x "$editor" ] || editor="/usr/bin/vi"
 [ -x "$editor" ] || error "EDITOR not found or not executable";
 
@@ -25,7 +25,7 @@ digraph G {
 
 	vim [href="http://www.vim.org/"]
 	dot [href="http://www.graphviz.org/"]
-	vimdot [href="file:///usr/bin/vimdot"]
+	vimdot [href="file:///usr/local/bin/vimdot"]
 
 	{vim dot} -> vimdot
 }

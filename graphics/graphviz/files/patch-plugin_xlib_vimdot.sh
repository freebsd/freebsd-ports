--- plugin/xlib/vimdot.sh.orig	2023-01-21 19:59:25 UTC
+++ plugin/xlib/vimdot.sh
@@ -9,7 +9,7 @@ fi
 error() { echo "$0: $*" >&2; exit 1; }
 
 # Try $EDITOR first, else try vim or vi
-editor="$(which $EDITOR)" || editor="/usr/bin/vim"
+editor="$(which $EDITOR)" || editor="/usr/local/bin/vim"
 [ -x "$editor" ] || editor="/usr/bin/vi"
 [ -x "$editor" ] || error "EDITOR not found or not executable";
 
@@ -29,7 +29,7 @@ digraph G {
 
 	vim [href="http://www.vim.org/"]
 	dot [href="http://www.graphviz.org/"]
-	vimdot [href="file:///usr/bin/vimdot"]
+	vimdot [href="file:///usr/local/bin/vimdot"]
 
 	{vim dot} -> vimdot
 }

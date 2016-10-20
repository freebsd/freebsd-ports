--- plugin/xlib/vimdot.sh.orig	2016-09-26 23:00:07 UTC
+++ plugin/xlib/vimdot.sh
@@ -3,7 +3,7 @@
 
 error() { echo "$0: $*" >&2; exit 1; }
 
-editor="/usr/bin/vim"
+editor="/usr/local/bin/vim"
 
 if ! test -x "$editor"; then error "the \"$editor\" editor not found or not executable"; fi
 
@@ -23,7 +23,7 @@ digraph G {
 
 	vim [href="http://www.vim.org/"]
 	dot [href="http://www.graphviz.org/"]
-	vimdot [href="file:///usr/bin/vimdot"]
+	vimdot [href="file:///usr/local/bin/vimdot"]
 
 	{vim dot} -> vimdot
 }

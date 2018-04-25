tmux-repl fails on FreeBSD and claims that tmux' version is too old even
though tmux >= 2 is installed.

The expr is only compatible with GNU expr.

https://github.com/mawww/kakoune/pull/2006

--- rc/extra/tmux-repl.kak.orig	2018-04-12 11:28:15 UTC
+++ rc/extra/tmux-repl.kak
@@ -4,8 +4,8 @@
 hook global KakBegin .* %{
     %sh{
         if [ -n "$TMUX" ]; then
-            VERSION_TMUX=$(tmux -V)
-            VERSION_TMUX=$(expr "${VERSION_TMUX}" : 'tmux \([0-9]*\|master\)')
+            VERSION_TMUX=$(tmux -V | cut -d' ' -f2)
+            VERSION_TMUX=${VERSION_TMUX%%.*}
 
             if [ "${VERSION_TMUX}" = "master" ] \
                 || [ "${VERSION_TMUX}" -ge 2 ]; then

We wrap `syntax on` in a try block so that it won't produce errors for
vim-tiny, which doens't include the runtime library.

We also source our own FreeBSD-specific defaults file.

--- runtime/defaults.vim.orig	2022-09-04 15:43:53 UTC
+++ runtime/defaults.vim
@@ -130,7 +130,9 @@ endif
 " GUI (which always has colors).
 if &t_Co > 2 || has("gui_running")
   " Revert with ":syntax off".
-  syntax on
+  try
+    syntax on
+  catch | endtry
 
   " I like highlighting strings inside C comments.
   " Revert with ":unlet c_comment_strings".
@@ -152,3 +154,5 @@ if has('langmap') && exists('+langremap')
   " compatible).
   set nolangremap
 endif
+
+source $VIMRUNTIME/defaults_freebsd.vim

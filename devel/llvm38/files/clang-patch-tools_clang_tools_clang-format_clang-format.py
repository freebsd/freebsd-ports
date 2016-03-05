--- tools/clang/tools/clang-format/clang-format.py.orig	2015-09-08 20:44:00 UTC
+++ tools/clang/tools/clang-format/clang-format.py
@@ -34,7 +34,7 @@ import vim
 
 # set g:clang_format_path to the path to clang-format if it is not on the path
 # Change this to the full path if clang-format is not on the path.
-binary = 'clang-format'
+binary = 'clang-format38'
 if vim.eval('exists("g:clang_format_path")') == "1":
   binary = vim.eval('g:clang_format_path')
 

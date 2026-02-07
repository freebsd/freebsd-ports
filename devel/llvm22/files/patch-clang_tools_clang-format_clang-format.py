--- clang/tools/clang-format/clang-format.py.orig
+++ clang/tools/clang-format/clang-format.py
@@ -49,7 +49,7 @@
 
 # set g:clang_format_path to the path to clang-format if it is not on the path
 # Change this to the full path if clang-format is not on the path.
-binary = "clang-format"
+binary = "clang-format%%LLVM_SUFFIX%%"
 if vim.eval('exists("g:clang_format_path")') == "1":
     binary = vim.eval("g:clang_format_path")
 

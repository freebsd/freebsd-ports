--- plugin/parinfer.vim.orig	2019-01-26 15:56:17 UTC
+++ plugin/parinfer.vim
@@ -9,6 +9,10 @@ if !exists('g:parinfer_force_balance')
 endif
 
 if !exists('g:parinfer_dylib_path')
+  let g:parinfer_dylib_path = 'libparinfer_rust.so'
+endif
+
+if !exists('g:parinfer_dylib_path')
   if has('macunix')
     let g:parinfer_dylib_path = expand('<sfile>:p:h:h'). '/target/release/libparinfer_rust.dylib'
   elseif has('unix')

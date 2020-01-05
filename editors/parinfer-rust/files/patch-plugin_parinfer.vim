--- plugin/parinfer.vim.orig	2020-01-04 23:58:23 UTC
+++ plugin/parinfer.vim
@@ -9,6 +9,10 @@ if !exists('g:parinfer_force_balance')
 endif
 
 if !exists('g:parinfer_dylib_path')
+  let g:parinfer_dylib_path = 'libparinfer_rust.so'
+endif
+
+if !exists('g:parinfer_dylib_path')
   let s:libdir = expand('<sfile>:p:h:h') . '/target/release'
   if has('macunix')
     let g:parinfer_dylib_path = s:libdir . '/libparinfer_rust.dylib'

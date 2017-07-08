--- ext/opengl/extconf.rb.orig	2017-06-25 14:46:52 UTC
+++ ext/opengl/extconf.rb
@@ -2,9 +2,6 @@ require 'mkmf'
 
 have_header('dlfcn.h') || have_header('windows.h')
 
-ok = have_library('dl', 'dlopen', ['dlfcn.h']) ||
-  have_library('user32', 'GetProcAddress', ['windows.h'])
-
 have_header 'stdint.h'
 have_header 'inttypes.h'
 
@@ -13,7 +10,5 @@ have_struct_member 'struct RFloat', 'flo
 have_type 'int64_t', 'stdint.h'
 have_type 'uint64_t', 'stdint.h'
 
-if ok then
   create_header
   create_makefile 'opengl/opengl'
-end

--- rakelib/blueprint.rb.orig	2011-05-13 18:20:02.000000000 -0700
+++ rakelib/blueprint.rb	2011-05-13 18:20:19.000000000 -0700
@@ -1,7 +1,9 @@
 Daedalus.blueprint do |i|
   gcc = i.gcc!
 
-  gcc.cflags << "-Ivm -Ivm/test/cxxtest -I. -I/usr/local/include -I/opt/local/include "
+  system_includes = "-I/usr/local/include -I/opt/local/include"
+
+  gcc.cflags << "-Ivm -Ivm/test/cxxtest -I. "
   gcc.cflags << "-pipe -Wall -fno-omit-frame-pointer"
   gcc.cflags << "-ggdb3 -Werror"
   gcc.cflags << "-DRBX_PROFILER"
@@ -162,6 +164,8 @@
   gcc.add_library onig
   gcc.add_library ltm
 
+  gcc.cflags << system_includes + " "
+
   if Rubinius::BUILD_CONFIG[:windows]
     winp = i.external_lib "vm/external_libs/winpthreads" do |l|
       l.cflags = ["-Ivm/external_libs/winpthreads/include"]

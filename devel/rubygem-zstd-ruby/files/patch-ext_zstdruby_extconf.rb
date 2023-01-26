--- ext/zstdruby/extconf.rb.orig	2023-01-26 09:37:28 UTC
+++ ext/zstdruby/extconf.rb
@@ -1,6 +1,6 @@
 require "mkmf"
 
-$CFLAGS = '-I. -O3 -std=c99'
+$CFLAGS = '-fdeclspec -I. -O3 -std=c99'
 $CPPFLAGS += " -fdeclspec" if CONFIG['CXX'] =~ /clang/
 
 Dir.chdir File.expand_path('..', __FILE__) do

--- ext/zstdruby/extconf.rb.orig	2026-06-18 06:57:35 UTC
+++ ext/zstdruby/extconf.rb
@@ -26,7 +26,7 @@ end
   name
 end
 
-$CFLAGS = '-I. -O3 -std=c99 -DZSTD_STATIC_LINKING_ONLY -DZSTD_MULTITHREAD -pthread -DDEBUGLEVEL=0 -fvisibility=hidden -DZSTDLIB_VISIBLE=\'__attribute__((visibility("hidden")))\' -DZSTDLIB_HIDDEN=\'__attribute__((visibility("hidden")))\''
+$CFLAGS = ' -fdeclspec -I. -O3 -std=c99 -DZSTD_STATIC_LINKING_ONLY -DZSTD_MULTITHREAD -pthread -DDEBUGLEVEL=0 -fvisibility=hidden -DZSTDLIB_VISIBLE=\'__attribute__((visibility("hidden")))\' -DZSTDLIB_HIDDEN=\'__attribute__((visibility("hidden")))\''
 $CPPFLAGS += " -fdeclspec" if CONFIG['CXX'] =~ /clang/
 
 # macOS specific: Use exported_symbols_list to control symbol visibility

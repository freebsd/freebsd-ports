--- ext/google/protobuf_c/extconf.rb.orig	2022-10-28 07:09:57 UTC
+++ ext/google/protobuf_c/extconf.rb
@@ -6,7 +6,7 @@ ext_name = "google/protobuf_c"
 
 dir_config(ext_name)
 
-if RUBY_PLATFORM =~ /darwin/ || RUBY_PLATFORM =~ /linux/
+if RUBY_PLATFORM =~ /darwin/ || RUBY_PLATFORM =~ /linux/ || RUBY_PLATFORM =~ /freebsd/
   $CFLAGS += " -std=gnu99 -O3 -DNDEBUG -fvisibility=hidden -Wall -Wsign-compare -Wno-declaration-after-statement"
 else
   $CFLAGS += " -std=gnu99 -O3 -DNDEBUG"

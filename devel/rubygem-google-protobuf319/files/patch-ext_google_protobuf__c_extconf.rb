--- ext/google/protobuf_c/extconf.rb.orig	2022-10-28 07:07:50 UTC
+++ ext/google/protobuf_c/extconf.rb
@@ -2,7 +2,7 @@
 
 require 'mkmf'
 
-if RUBY_PLATFORM =~ /darwin/ || RUBY_PLATFORM =~ /linux/
+if RUBY_PLATFORM =~ /darwin/ || RUBY_PLATFORM =~ /linux/ || RUBY_PLATFORM =~ /freebsd/
   $CFLAGS += " -std=gnu99 -O3 -DNDEBUG -fvisibility=hidden -Wall -Wsign-compare -Wno-declaration-after-statement"
 else
   $CFLAGS += " -std=gnu99 -O3 -DNDEBUG"

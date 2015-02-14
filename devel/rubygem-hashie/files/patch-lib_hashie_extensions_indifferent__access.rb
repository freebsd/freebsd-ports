--- lib/hashie/extensions/indifferent_access.rb.orig	2015-02-06 12:45:47 UTC
+++ lib/hashie/extensions/indifferent_access.rb
@@ -76,16 +76,16 @@ module Hashie
       # is injecting itself into member hashes.
       def convert!
         keys.each do |k|
-          regular_writer convert_key(k), convert_value(regular_delete(k))
+          regular_writer convert_key(k), indifferent_value(regular_delete(k))
         end
         self
       end
 
-      def convert_value(value)
+      def indifferent_value(value)
         if hash_lacking_indifference?(value)
           IndifferentAccess.inject!(value)
         elsif value.is_a?(::Array)
-          value.replace(value.map { |e| convert_value(e) })
+          value.replace(value.map { |e| indifferent_value(e) })
         else
           value
         end
@@ -104,7 +104,7 @@ module Hashie
       end
 
       def indifferent_writer(key, value)
-        regular_writer convert_key(key), convert_value(value)
+        regular_writer convert_key(key), indifferent_value(value)
       end
 
       def indifferent_fetch(key, *args, &block)

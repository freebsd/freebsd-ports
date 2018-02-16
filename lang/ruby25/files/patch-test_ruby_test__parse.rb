--- test/ruby/test_parse.rb.orig	2017-12-20 00:09:51 UTC
+++ test/ruby/test_parse.rb
@@ -746,6 +746,12 @@ x = __ENCODING__
         end
       END
     end
+    assert_raise(SyntaxError) do
+      eval "#{<<~"begin;"}\n#{<<~'end;'}", nil, __FILE__, __LINE__+1
+      begin;
+        x, true
+      end;
+    end
   end
 
   def test_block_dup

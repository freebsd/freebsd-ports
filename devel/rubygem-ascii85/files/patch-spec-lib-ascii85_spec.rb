Obtained from:	https://github.com/DataWraith/ascii85gem/commit/b7480db0bf18af3a13f9b56215d283e192930ad1

--- spec/lib/ascii85_spec.rb.orig	2024-09-07 12:17:27 UTC
+++ spec/lib/ascii85_spec.rb
@@ -35,7 +35,10 @@ TEST_CASES = {
       '<~j+42iJVN3:K&_E6j+<0KJW/W?W8iG`j+EuaK"9on^Z0sZj+FJoK:LtSKB%T?~>',
 
   [Math::PI].pack('G') => '<~5RAV2<(&;T~>',
-  [Math::E].pack('G') => '<~5R"n0M\\K6,~>'
+  [Math::E].pack('G') => '<~5R"n0M\\K6,~>',
+
+  # Minified example from Github issue 8
+  "\x9B\xB6\xB9+\x91" => '<~S$ojXOU~>'
 }.freeze
 
 describe Ascii85 do

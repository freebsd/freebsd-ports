--- test/dbi/tc_types.rb.orig	2015-05-27 17:33:53 UTC
+++ test/dbi/tc_types.rb
@@ -114,11 +114,7 @@ class TC_DBI_Type < Test::Unit::TestCase
         d = Date.today
         assert_equal(DateTime.parse(d.to_s).to_s, klass.parse(d).to_s)
 
-        md = "10-11"
-
-        if RUBY_VERSION =~ /^1\.9/
             md = "11-10"
-        end
 
         # be sure we're actually getting the right data back
         assert_equal(

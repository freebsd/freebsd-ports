--- tools/create-reference.rb.orig	2013-06-17 14:02:54.000000000 +0000
+++ tools/create-reference.rb	2013-06-17 14:03:31.000000000 +0000
@@ -5,6 +5,11 @@
 # Use under a public domain license.
 #
 
+if RUBY_VERSION != /^1.8/
+  Encoding.default_external = Encoding::UTF_8
+  Encoding.default_internal = Encoding::UTF_8
+end
+
 class Argument
     attr_accessor :name, :data_type, :doc
     def initialize

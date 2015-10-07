--- lib/rdoc/single_class.rb	2014-11-26 19:29:03 UTC
+++ lib/rdoc/single_class.rb
@@ -10,6 +10,10 @@ def ancestors
     superclass ? super + [superclass] : super
   end
 
+  def aref_prefix # :nodoc:
+    'sclass'
+  end
+
   ##
   # The definition of this singleton class, <tt>class << MyClassName</tt>
 

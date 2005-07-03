--- lib/xmlrpc/utils.rb.orig	Fri Jul  1 07:38:00 2005
+++ lib/xmlrpc/utils.rb	Fri Jul  1 07:38:55 2005
@@ -138,7 +138,7 @@
 
     def get_methods(obj, delim=".")
       prefix = @prefix + delim
-      obj.class.public_instance_methods.collect { |name|
+      obj.class.public_instance_methods(false).collect { |name|
         [prefix + name, obj.method(name).to_proc, nil, nil] 
       }
     end

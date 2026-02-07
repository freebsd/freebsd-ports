--- tool/mkconfig.rb.orig	2019-12-25 09:50:58 UTC
+++ tool/mkconfig.rb
@@ -160,8 +160,9 @@ def vars.expand(val, config = self)
   val.replace(newval) unless newval == val
   val
 end
-prefix = vars.expand(vars["prefix"] ||= "")
-rubyarchdir = vars.expand(vars["rubyarchdir"] ||= "")
+prefix = vars.expand(vars["rubyarchdir"])
+major, minor, *rest = RUBY_VERSION.split('.')
+rubyarchdir = "/lib/ruby/#{major}.#{minor}/#{arch}"
 relative_archdir = rubyarchdir.rindex(prefix, 0) ? rubyarchdir[prefix.size..-1] : rubyarchdir
 
 puts %[\

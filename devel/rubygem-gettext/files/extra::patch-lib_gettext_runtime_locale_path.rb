--- lib/gettext/runtime/locale_path.rb.orig	2011-09-07 00:13:32.000000000 -0700
+++ lib/gettext/runtime/locale_path.rb	2011-09-07 00:13:46.000000000 -0700
@@ -52,9 +52,6 @@
         default_path_rules += DEFAULT_RULES
         
         load_path = $LOAD_PATH
-        if defined? ::Gem
-          load_path += Gem.all_load_paths
-        end
         load_path.map!{|v| v.match(/(.*?)(\/lib)*?$/); $1}
         load_path.each {|path|
           default_path_rules += [

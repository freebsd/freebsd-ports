--- extconf.rb.orig	Fri Jul 25 21:29:57 2003
+++ extconf.rb	Tue Jul 29 16:13:42 2003
@@ -10,7 +10,7 @@
    name
 end
 
-if ! find_library(resolve(CONFIG["LIBRUBY"]).sub(/^lib(.*)\.\w+\z/, '\\1'), 
+if ! find_library(resolve(CONFIG["LIBRUBY"]).sub(/^lib([^.]*).*\z/, '\\1'), 
                   "ruby_init", resolve(CONFIG["archdir"]))
    raise "can't find -lruby"
 end

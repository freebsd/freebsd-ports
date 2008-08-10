--- lib/optparse.rb.orig	2008-08-10 14:34:06.000000000 +0400
+++ lib/optparse.rb	2008-08-10 14:34:32.000000000 +0400
@@ -379,7 +379,7 @@
       while s = lopts.shift
         l = left[-1].length + s.length
         l += arg.length if left.size == 1 && arg
-        l < max or left << ''
+        l < max or sopts.empty? or left << ''
         left[-1] << if left[-1].empty? then ' ' * 4 else ', ' end << s
       end
 
@@ -1474,6 +1474,7 @@
   #
   def environment(env = File.basename($0, '.*'))
     env = ENV[env] || ENV[env.upcase] or return
+    require 'shellwords'
     parse(*Shellwords.shellwords(env))
   end
 

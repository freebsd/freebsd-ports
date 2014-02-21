--- ./lib/mkrf/availability.rb.orig	2014-02-21 20:52:50.940993647 +0000
+++ ./lib/mkrf/availability.rb	2014-02-21 20:52:57.428993579 +0000
@@ -150,7 +150,7 @@
       if RUBY_PLATFORM =~ /mswin/
         @loaded_libs.join(' ')
       else
-        @loaded_libs.collect {|l| "-l#{l}"}.join(' ')
+        @loaded_libs.collect {|l| if l =~ /-/ then "#{l}" else "-l#{l}" end}.join(' ')
       end
     end
     

--- extconf.rb.orig	2010-11-30 19:41:45.000000000 +0800
+++ extconf.rb	2011-12-18 16:36:33.312316430 +0800
@@ -3,8 +3,9 @@
 File::unlink("Makefile") if (File::exist?("Makefile"))
 dir_config('kyotocabinet')
 
-home = ENV["HOME"]
-ENV["PATH"] = ENV["PATH"] + ":/usr/local/bin:$home/bin:."
+#home = ENV["HOME"]
+#ENV["PATH"] = ENV["PATH"] + ":/usr/local/bin:$home/bin:."
+ENV["PATH"] = '%s:%s' % [with_config('bindir'), ENV["PATH"]]
 kccflags = `kcutilmgr conf -i 2>/dev/null`.chomp
 kcldflags = `kcutilmgr conf -l 2>/dev/null`.chomp
 kcldflags = kcldflags.gsub(/-l[\S]+/, "").strip

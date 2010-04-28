--- extconf.rb.orig	2010-04-28 13:27:42.120543437 +0900
+++ extconf.rb	2010-04-28 13:04:57.387073893 +0900
@@ -3,8 +3,9 @@
 File::unlink("Makefile") if (File::exist?("Makefile"))
 dir_config('kyotocabinet')
 
-home = ENV["HOME"]
-ENV["PATH"] = ENV["PATH"] + ":/usr/local/bin:$home/bin:."
+#home = ENV["HOME"]
+#ENV["PATH"] = ENV["PATH"] + ":/usr/local/bin:$home/bin:."
+ENV["PATH"] = '%s:%s' % [with_config('bindir'), ENV["PATH"]]
 kccflags = `kcutilcodec conf -i 2>/dev/null`.chomp
 kcldflags = `kcutilcodec conf -l 2>/dev/null`.chomp
 kcldflags = kcldflags.gsub(/-l[\S]+/, "").strip

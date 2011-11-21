--- tool/rbinstall.rb.orig	2011-07-30 07:19:11.000000000 -0700
+++ tool/rbinstall.rb	2011-11-19 00:08:56.000000000 -0800
@@ -292,6 +292,7 @@
 
 bindir = CONFIG["bindir"]
 libdir = CONFIG["libdir"]
+libdatadir = CONFIG["prefix"] + "/" + "libdata"
 archhdrdir = rubyhdrdir = CONFIG["rubyhdrdir"]
 archhdrdir += "/" + CONFIG["arch"]
 rubylibdir = CONFIG["rubylibdir"]
@@ -349,7 +350,7 @@
 install?(:local, :arch, :data) do
   pc = CONFIG["ruby_pc"]
   if pc and File.file?(pc) and File.size?(pc)
-    prepare "pkgconfig data", pkgconfigdir = File.join(libdir, "pkgconfig")
+    prepare "pkgconfig data", pkgconfigdir = File.join(libdatadir, "pkgconfig")
     install pc, pkgconfigdir, :mode => $data_mode
   end
 end
@@ -531,54 +532,6 @@
   end
 end
 
-install?(:ext, :comm, :gem) do
-  $:.unshift(File.join(srcdir, "lib"))
-  require("rubygems.rb")
-  gem_dir = Gem.default_dir
-  directories = Gem.ensure_gem_subdirectories(gem_dir)
-  prepare "default gems", gem_dir, directories
-
-  spec_dir = File.join(gem_dir, directories.grep(/^spec/)[0])
-  File.foreach(File.join(srcdir, "defs/default_gems")) do |line|
-    line.chomp!
-    line.sub!(/\s*#.*/, '')
-    next if line.empty?
-    words = []
-    line.scan(/\G\s*([^\[\]\s]+|\[([^\[\]]*)\])/) do
-      words << ($2 ? $2.split : $1)
-    end
-    name, src, execs = *words
-    next unless name and src
-    execs ||= []
-    src = File.join(srcdir, src)
-    version = open(src) {|f| f.find {|s| /^\s*\w*VERSION\s*=(?!=)/ =~ s}} or next
-    version = version.split(%r"=\s*", 2)[1].strip[/\A([\'\"])(.*?)\1/, 2]
-    full_name = "#{name}-#{version}"
-
-    puts "#{" "*30}#{name} #{version}"
-    open_for_install(File.join(spec_dir, "#{full_name}.gemspec"), $data_mode) do
-      <<-GEMSPEC
-Gem::Specification.new do |s|
-  s.name = #{name.dump}
-  s.version = #{version.dump}
-  s.summary = "This #{name} is bundled with Ruby"
-  s.executables = #{execs.inspect}
-end
-      GEMSPEC
-    end
-
-    unless execs.empty? then
-      bin_dir = File.join(gem_dir, 'gems', full_name, 'bin')
-      makedirs(bin_dir)
-
-      execs.each do |exec|
-        exec = File.join(srcdir, 'bin', exec)
-        install(exec, bin_dir, :mode => $prog_mode)
-      end
-    end
-  end
-end
-
 parse_args()
 
 include FileUtils

--- tool/rbinstall.rb.orig	2015-03-25 03:33:14.000000000 +0000
+++ tool/rbinstall.rb	2015-04-13 18:16:00.160952000 +0000
@@ -311,6 +311,7 @@
 libdir = CONFIG[CONFIG.fetch("libdirname", "libdir"), true]
 rubyhdrdir = CONFIG["rubyhdrdir", true]
 archhdrdir = CONFIG["rubyarchhdrdir"] || (rubyhdrdir + "/" + CONFIG['arch'])
+libdatadir = CONFIG["prefix", true] + "/" + "libdata"
 rubylibdir = CONFIG["rubylibdir", true]
 archlibdir = CONFIG["rubyarchdir", true]
 sitelibdir = CONFIG["sitelibdir"]
@@ -366,7 +367,7 @@
 install?(:local, :arch, :data) do
   pc = CONFIG["ruby_pc"]
   if pc and File.file?(pc) and File.size?(pc)
-    prepare "pkgconfig data", pkgconfigdir = File.join(libdir, "pkgconfig")
+    prepare "pkgconfig data", pkgconfigdir = File.join(libdatadir, "pkgconfig")
     install pc, pkgconfigdir, :mode => $data_mode
   end
 end
@@ -653,86 +654,6 @@
 end
 # :startdoc:
 
-install?(:ext, :comm, :gem) do
-  $:.unshift(File.join(srcdir, "lib"))
-  require("rubygems.rb")
-  gem_dir = Gem.default_dir
-  directories = Gem.ensure_gem_subdirectories(gem_dir, :mode => $dir_mode)
-  prepare "default gems", gem_dir, directories
-
-  spec_dir = File.join(gem_dir, directories.grep(/^spec/)[0])
-  default_spec_dir = "#{spec_dir}/default"
-  makedirs(default_spec_dir)
-
-  gems = {}
-  File.foreach(File.join(srcdir, "defs/default_gems")) do |line|
-    line.chomp!
-    line.sub!(/\s*#.*/, '')
-    next if line.empty?
-    words = []
-    line.scan(/\G\s*([^\[\]\s]+|\[([^\[\]]*)\])/) do
-      words << ($2 ? $2.split : $1)
-    end
-    name, base_dir, src, execs = *words
-    next unless name and base_dir and src
-
-    src       = File.join(srcdir, src)
-    base_dir  = File.join(srcdir, base_dir)
-    specgen   = RbInstall::Specs::Generator.new(name, base_dir, src, execs || [])
-    gems[name] ||= specgen
-  end
-
-  Dir.glob(srcdir+"/{lib,ext}/**/*.gemspec").each do |src|
-    specgen   = RbInstall::Specs::Reader.new(src)
-    gems[specgen.gemspec.name] ||= specgen
-  end
-
-  gems.sort.each do |name, specgen|
-    gemspec   = specgen.gemspec
-    base_dir  = specgen.src.sub(/\A#{Regexp.escape(srcdir)}\//, "")
-    full_name = "#{gemspec.name}-#{gemspec.version}"
-
-    puts "#{" "*30}#{gemspec.name} #{gemspec.version}"
-    gemspec_path = File.join(default_spec_dir, "#{full_name}.gemspec")
-    open_for_install(gemspec_path, $data_mode) do
-      specgen.spec_source
-    end
-
-    unless gemspec.executables.empty? then
-      bin_dir = File.join(gem_dir, 'gems', full_name, 'bin')
-      makedirs(bin_dir)
-
-      execs = gemspec.executables.map {|exec| File.join(srcdir, 'bin', exec)}
-      install(execs, bin_dir, :mode => $prog_mode)
-    end
-  end
-end
-
-install?(:ext, :comm, :gem) do
-  begin
-    require "zlib"
-  rescue LoadError
-  end
-  if defined?(Zlib)
-    require 'pathname'
-    gem_dir = Gem.default_dir
-    directories = Gem.ensure_gem_subdirectories(gem_dir, :mode => $dir_mode)
-    prepare "bundle gems", gem_dir, directories
-    Dir.glob(srcdir+'/gems/*.gem').each do |gem|
-      Gem.install gem, Gem::Requirement.default, :install_dir => with_destdir(Gem.dir), :domain => :local, :ignore_dependencies => true
-      gemname = Pathname(gem).basename
-      puts "#{" "*30}#{gemname}"
-    end
-    # fix directory permissions
-    # TODO: Gem.install should accept :dir_mode option or something
-    File.chmod($dir_mode, *Dir.glob(with_destdir(Gem.dir)+"/**/"))
-    # fix .gemspec permissions
-    File.chmod($data_mode, *Dir.glob(with_destdir(Gem.dir)+"/specifications/*.gemspec"))
-  else
-    puts "skip installing bundle gems because of lacking zlib"
-  end
-end
-
 parse_args()
 
 include FileUtils

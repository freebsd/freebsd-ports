--- tool/rbinstall.rb.orig	2015-11-16 06:33:17 UTC
+++ tool/rbinstall.rb
@@ -322,6 +322,7 @@ bindir = CONFIG["bindir", true]
 libdir = CONFIG[CONFIG.fetch("libdirname", "libdir"), true]
 rubyhdrdir = CONFIG["rubyhdrdir", true]
 archhdrdir = CONFIG["rubyarchhdrdir"] || (rubyhdrdir + "/" + CONFIG['arch'])
+libdatadir = CONFIG["prefix", true] + "/" + "libdata"
 rubylibdir = CONFIG["rubylibdir", true]
 archlibdir = CONFIG["rubyarchdir", true]
 sitelibdir = CONFIG["sitelibdir"]
@@ -376,7 +377,7 @@ end
 install?(:local, :arch, :data) do
   pc = CONFIG["ruby_pc"]
   if pc and File.file?(pc) and File.size?(pc)
-    prepare "pkgconfig data", pkgconfigdir = File.join(libdir, "pkgconfig")
+    prepare "pkgconfig data", pkgconfigdir = File.join(libdatadir, "pkgconfig")
     install pc, pkgconfigdir, :mode => $data_mode
   end
 end
@@ -695,88 +696,6 @@ end
 
 # :startdoc:
 
-install?(:ext, :comm, :gem) do
-  gem_dir = Gem.default_dir
-  directories = Gem.ensure_gem_subdirectories(gem_dir, :mode => $dir_mode)
-  prepare "default gems", gem_dir, directories
-
-  spec_dir = File.join(gem_dir, directories.grep(/^spec/)[0])
-  default_spec_dir = "#{spec_dir}/default"
-  makedirs(default_spec_dir)
-
-  gems = {}
-
-  Dir.glob(srcdir+"/{lib,ext}/**/*.gemspec").each do |src|
-    specgen   = RbInstall::Specs::Reader.new(src)
-    gems[specgen.gemspec.name] ||= specgen
-  end
-
-  gems.sort.each do |name, specgen|
-    gemspec   = specgen.gemspec
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
-      install(execs, bin_dir, :mode => $script_mode)
-    end
-  end
-end
-
-install?(:ext, :comm, :gem) do
-  gem_dir = Gem.default_dir
-  directories = Gem.ensure_gem_subdirectories(gem_dir, :mode => $dir_mode)
-  prepare "bundle gems", gem_dir, directories
-  install_dir = with_destdir(gem_dir)
-  installed_gems = {}
-  options = {
-    :install_dir => install_dir,
-    :bin_dir => with_destdir(bindir),
-    :domain => :local,
-    :ignore_dependencies => true,
-    :dir_mode => $dir_mode,
-    :data_mode => $data_mode,
-    :prog_mode => $prog_mode,
-    :wrappers => true,
-    :format_executable => true,
-  }
-  Gem::Specification.each_spec([srcdir+'/gems/*']) do |spec|
-    ins = RbInstall::UnpackedInstaller.new(spec, options)
-    puts "#{" "*30}#{spec.name} #{spec.version}"
-    ins.install
-    File.chmod($data_mode, File.join(install_dir, "specifications", "#{spec.full_name}.gemspec"))
-    installed_gems[spec.full_name] = true
-  end
-  installed_gems, gems = Dir.glob(srcdir+'/gems/*.gem').partition {|gem| installed_gems.key?(File.basename(gem, '.gem'))}
-  unless installed_gems.empty?
-    install installed_gems, gem_dir+"/cache"
-  end
-  next if gems.empty?
-  if defined?(Zlib)
-    Gem.instance_variable_set(:@ruby, with_destdir(File.join(bindir, ruby_install_name)))
-    gems.each do |gem|
-      Gem.install(gem, Gem::Requirement.default, options)
-      gemname = File.basename(gem)
-      puts "#{" "*30}#{gemname}"
-    end
-    # fix directory permissions
-    # TODO: Gem.install should accept :dir_mode option or something
-    File.chmod($dir_mode, *Dir.glob(install_dir+"/**/"))
-    # fix .gemspec permissions
-    File.chmod($data_mode, *Dir.glob(install_dir+"/specifications/*.gemspec"))
-  else
-    puts "skip installing bundle gems because of lacking zlib"
-  end
-end
-
 parse_args()
 
 include FileUtils

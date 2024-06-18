--- ext/compile.rb.orig	2024-06-15 17:30:56 UTC
+++ ext/compile.rb
@@ -6,31 +6,6 @@ require_relative '../lib/aws-crt/platforms'
 require 'shellwords'
 require_relative '../lib/aws-crt/platforms'
 
-CMAKE_PATH = find_executable('cmake3') || find_executable('cmake')
-abort 'Missing cmake' unless CMAKE_PATH
-CMAKE = File.basename(CMAKE_PATH)
-
-def cmake_version
-  version_str = `#{CMAKE} --version`
-  match = /(\d+)\.(\d+)\.(\d+)/.match(version_str)
-  [match[1].to_i, match[2].to_i, match[3].to_i]
-end
-
-CMAKE_VERSION = cmake_version
-
-# whether installed cmake supports --parallel build flag
-def cmake_has_parallel_flag?
-  (CMAKE_VERSION <=> [3, 12]) >= 0
-end
-
-def run_cmd(args)
-  # use shellwords.join() for printing, don't pass that string to system().
-  # system() does better cross-platform when the args array is passed in.
-  cmd_str = Shellwords.join(args)
-  puts cmd_str
-  system(*args) || raise("Error running: #{cmd_str}")
-end
-
 def find_file(name, search_dirs, base_dir)
   search_dirs.each do |search_dir|
     dir = File.expand_path(search_dir, base_dir)
@@ -43,47 +18,10 @@ def compile_bin(cpu = host_cpu)
 # Compile bin to expected location
 def compile_bin(cpu = host_cpu)
   platform = target_platform(cpu)
-  native_dir = File.expand_path('../aws-crt-ffi', File.dirname(__FILE__))
   tmp_dir = File.expand_path("../tmp/#{platform.cpu}", File.dirname(__FILE__))
   tmp_build_dir = File.expand_path('build', tmp_dir)
 
-  # We need cmake to "install" aws-crt-ffi so that the binaries end up in a
-  # predictable location. But cmake still adds subdirectories we don't want,
-  # so we'll "install" under tmp, and manually copy to bin/ after that.
-  tmp_install_dir = File.expand_path('install', tmp_dir)
-
-  build_type = 'RelWithDebInfo'
-
-  config_cmd = [
-    CMAKE,
-    "-H#{native_dir}",
-    "-B#{tmp_build_dir}",
-    "-DCMAKE_INSTALL_PREFIX=#{tmp_install_dir}",
-    "-DCMAKE_BUILD_TYPE=#{build_type}",
-    '-DBUILD_TESTING=OFF',
-  ]
-
-  # macOS can cross-compile for arm64 or x86_64.
-  # This lets us prepare both types of gems from either type of machine.
-  if platform.os == 'darwin'
-    config_cmd.append("-DCMAKE_OSX_ARCHITECTURES=#{platform.cpu}")
-  end
-
-  build_cmd = [
-    CMAKE,
-    '--build', tmp_build_dir,
-    '--target', 'install',
-    '--config', build_type,
-  ]
-
-  # Build using all processors
-  if cmake_has_parallel_flag?
-    build_cmd.append('--parallel')
-    build_cmd.append(Etc.nprocessors.to_s)
-  end
-
-  run_cmd(config_cmd)
-  run_cmd(build_cmd)
+  tmp_install_dir = '%%LOCALBASE%%'
 
   # Move file to bin/, instead of where cmake installed it under tmp/
   bin_dir = crt_bin_dir(platform)

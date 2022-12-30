--- ext/sqlite3/extconf.rb.orig	2022-11-27 23:59:11 UTC
+++ ext/sqlite3/extconf.rb
@@ -1,5 +1,4 @@
 require "mkmf"
-require "mini_portile2"
 require "yaml"
 
 module Sqlite3
@@ -49,42 +48,6 @@ module Sqlite3
       end
 
       def configure_packaged_libraries
-        minimal_recipe.tap do |recipe|
-          recipe.configure_options += ["--enable-shared=no", "--enable-static=yes"]
-          ENV.to_h.tap do |env|
-            additional_cflags = [
-              "-fPIC", # needed for linking the static library into a shared library
-              "-O2", # see https://github.com/sparklemotion/sqlite3-ruby/issues/335 for some benchmarks
-            ]
-            env["CFLAGS"] = [env["CFLAGS"], additional_cflags].flatten.join(" ")
-            recipe.configure_options += env.select { |k,v| ENV_ALLOWLIST.include?(k) }
-                                           .map { |key, value| "#{key}=#{value.strip}" }
-          end
-
-          unless File.exist?(File.join(recipe.target, recipe.host, recipe.name, recipe.version))
-            recipe.cook
-          end
-          recipe.activate
-
-          # on macos, pkg-config will not return --cflags without this
-          ENV["PKG_CONFIG_ALLOW_SYSTEM_CFLAGS"] = "t"
-
-          lib_path = File.join(recipe.path, "lib")
-          pcfile = File.join(lib_path, "pkgconfig", "sqlite3.pc")
-          abort_pkg_config("pkg_config") unless pkg_config(pcfile)
-
-          # see https://bugs.ruby-lang.org/issues/18490
-          flags = xpopen(["pkg-config", "--libs", "--static", pcfile], err: [:child, :out], &:read)
-          abort_pkg_config("xpopen") unless $?.success?
-          flags = flags.split
-
-          # see https://github.com/flavorjones/mini_portile/issues/118
-          "-L#{lib_path}".tap do |lib_path_flag|
-            flags.prepend(lib_path_flag) unless flags.include?(lib_path_flag)
-          end
-
-          flags.each { |flag| append_ldflags(flag) }
-        end
       end
 
       def configure_extension
@@ -125,15 +88,6 @@ module Sqlite3
       end
 
       def minimal_recipe
-        MiniPortile.new(libname, sqlite3_config[:version]).tap do |recipe|
-          if sqlite_source_dir
-            recipe.source_directory = sqlite_source_dir
-          else
-            recipe.files = sqlite3_config[:files]
-            recipe.target = File.join(package_root_dir, "ports")
-            recipe.patch_files = Dir[File.join(package_root_dir, "patches", "*.patch")].sort
-          end
-        end
       end
 
       def package_root_dir
@@ -141,12 +95,9 @@ module Sqlite3
       end
 
       def sqlite3_config
-        mini_portile_config[:sqlite3]
       end
 
       def mini_portile_config
-        # TODO: once Ruby 2.7 is no longer supported, use symbolize_names: true
-        YAML.load_file(File.join(package_root_dir, "dependencies.yml"))
       end
 
       def abort_could_not_find(missing)
@@ -158,7 +109,6 @@ module Sqlite3
       end
 
       def cross_build?
-        enable_config("cross-build")
       end
 
       def sqlite_source_dir
@@ -166,7 +116,6 @@ module Sqlite3
       end
 
       def download
-        minimal_recipe.download
       end
 
       def print_help

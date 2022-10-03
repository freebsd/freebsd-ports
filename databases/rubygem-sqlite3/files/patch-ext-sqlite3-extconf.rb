--- ext/sqlite3/extconf.rb.orig	2022-10-03 13:15:30 UTC
+++ ext/sqlite3/extconf.rb
@@ -1,5 +1,4 @@
 require "mkmf"
-require "mini_portile2"
 require "yaml"
 
 module Sqlite3
@@ -49,33 +48,6 @@ module Sqlite3
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
-          ENV["PKG_CONFIG_ALLOW_SYSTEM_CFLAGS"] = "t" # on macos, pkg-config will not return --cflags without this
-          pcfile = File.join(recipe.path, "lib", "pkgconfig", "sqlite3.pc")
-          if pkg_config(pcfile)
-            # see https://bugs.ruby-lang.org/issues/18490
-            libs = xpopen(["pkg-config", "--libs", "--static", pcfile], err: [:child, :out], &:read)
-            libs.split.each { |lib| append_ldflags(lib) } if $?.success?
-          else
-            abort("\nCould not configure the build properly. Please install either the `pkg-config` utility or the `pkg-config` rubygem.\n\n")
-          end
-        end
       end
 
       def configure_extension
@@ -116,11 +88,6 @@ module Sqlite3
       end
 
       def minimal_recipe
-        MiniPortile.new(libname, sqlite3_config[:version]).tap do |recipe|
-          recipe.files = sqlite3_config[:files]
-          recipe.target = File.join(package_root_dir, "ports")
-          recipe.patch_files = Dir[File.join(package_root_dir, "patches", "*.patch")].sort
-        end
       end
 
       def package_root_dir
@@ -128,12 +95,9 @@ module Sqlite3
       end
 
       def sqlite3_config
-        mini_portile_config[:sqlite3]
       end
 
       def mini_portile_config
-        # TODO: once Ruby 2.7 is no longer supported, use symbolize_names: true
-        YAML.load_file(File.join(package_root_dir, "dependencies.yml"))
       end
 
       def abort_could_not_find(missing)
@@ -141,11 +105,9 @@ module Sqlite3
       end
 
       def cross_build?
-        enable_config("cross-build")
       end
 
       def download
-        minimal_recipe.download
       end
 
       def print_help

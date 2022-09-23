--- ext/sqlite3/extconf.rb.orig	2022-09-10 15:17:36 UTC
+++ ext/sqlite3/extconf.rb
@@ -1,5 +1,4 @@
 require "mkmf"
-require "mini_portile2"
 
 module Sqlite3
   module ExtConf
@@ -48,33 +47,6 @@ module Sqlite3
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
@@ -115,11 +87,6 @@ module Sqlite3
       end
 
       def minimal_recipe
-        MiniPortile.new(libname, sqlite3_config[:version]).tap do |recipe|
-          recipe.files = sqlite3_config[:files]
-          recipe.target = File.join(package_root_dir, "ports")
-          recipe.patch_files = Dir[File.join(package_root_dir, "patches", "*.patch")].sort
-        end
       end
 
       def package_root_dir
@@ -127,27 +94,9 @@ module Sqlite3
       end
 
       def sqlite3_config
-        mini_portile_config[:sqlite3]
       end
 
       def mini_portile_config
-        {
-          sqlite3: {
-            # checksum verified by first checking the published sha3(256) checksum against https://sqlite.org/download.html:
-            #
-            # $ sha3sum -a 256 ports/archives/sqlite-autoconf-3390300.tar.gz
-            # dfa055c70724cd63f0b7da6e9f53530d8da51fe021e3f864d58c7c847d590e1d  ports/archives/sqlite-autoconf-3390300.tar.gz
-            #
-            # $ sha256sum ports/archives/sqlite-autoconf-3390300.tar.gz
-            # 7868fb3082be3f2cf4491c6fba6de2bddcbc293a35fefb0624ee3c13f01422b9  ports/archives/sqlite-autoconf-3390300.tar.gz
-            #
-            version: "3.39.3",
-            files: [{
-                      url: "https://www.sqlite.org/2022/sqlite-autoconf-3390300.tar.gz",
-                      sha256: "7868fb3082be3f2cf4491c6fba6de2bddcbc293a35fefb0624ee3c13f01422b9",
-                    }],
-          }
-        }
       end
 
       def abort_could_not_find(missing)
@@ -156,10 +105,6 @@ module Sqlite3
 
       def cross_build?
         enable_config("cross-build")
-      end
-
-      def download
-        minimal_recipe.download
       end
 
       def print_help

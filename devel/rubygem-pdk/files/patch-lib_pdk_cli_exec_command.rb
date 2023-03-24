--- lib/pdk/cli/exec/command.rb.orig	2023-03-24 21:05:48 UTC
+++ lib/pdk/cli/exec/command.rb
@@ -185,7 +185,7 @@ module PDK
 
             resolved_env['GEM_HOME'] = PDK::Util::RubyVersion.gem_home
             gem_path = PDK::Util::RubyVersion.gem_path
-            resolved_env['GEM_PATH'] = gem_path.empty? ? resolved_env['GEM_HOME'] : gem_path
+            # resolved_env['GEM_PATH'] = gem_path.empty? ? resolved_env['GEM_HOME'] : gem_path
 
             # Make sure invocation of Ruby prefers our private installation.
             package_binpath = PDK::Util.package_install? ? File.join(PDK::Util.pdk_package_basedir, 'bin') : nil

--- lib/pdk/util/bundler.rb.orig	2022-02-13 01:09:14 UTC
+++ lib/pdk/util/bundler.rb
@@ -21,12 +21,7 @@ module PDK
           return
         end
 
-        unless bundle.locked?
-          # Generate initial default Gemfile.lock, either from package cache or
-          # by invoking `bundle lock`
-          bundle.lock!
-        end
-
+        if bundle.locked?
         # Check if all dependencies will be available once we update the lockfile.
         begin
           original_lockfile = bundle.gemfile_lock
@@ -40,6 +35,7 @@ module PDK
         end
 
         bundle.update_lock!(with: gem_overrides, local: all_deps_available)
+        end
 
         # If there are missing dependencies after updating the lockfile, let `bundle install`
         # go out and get them. If the specified puppet gem version points to a remote location

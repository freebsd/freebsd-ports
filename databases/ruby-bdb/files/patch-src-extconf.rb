--- src/extconf.rb.orig	2015-01-22 16:09:31 UTC
+++ src/extconf.rb
@@ -36,16 +36,16 @@
 
 if unknown = enable_config("unknown")
    libs = if CONFIG.key?("LIBRUBYARG_STATIC")
-	     Config::expand(CONFIG["LIBRUBYARG_STATIC"].dup).sub(/^-l/, '')
+	     RbConfig::expand(CONFIG["LIBRUBYARG_STATIC"].dup).sub(/^-l/, '')
 	  else
-	     Config::expand(CONFIG["LIBRUBYARG"].dup).sub(/lib([^.]*).*/, '\\1')
+	     RbConfig::expand(CONFIG["LIBRUBYARG"].dup).sub(/lib([^.]*).*/, '\\1')
 	  end
    unknown = find_library(libs, "ruby_init", 
-			  Config::expand(CONFIG["archdir"].dup))
+			  RbConfig::expand(CONFIG["archdir"].dup))
 end
 
 inc_dir, lib_dir = dir_config("db", "/usr/include", "/usr/lib")
-case Config::CONFIG["arch"]
+case RbConfig::CONFIG["arch"]
 when /solaris2/
    $DLDFLAGS ||= ""
    $DLDFLAGS += " -R#{lib_dir}"

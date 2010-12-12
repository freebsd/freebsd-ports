--- ext/oci8/oraconf.rb.orig	Fri Jan 19 15:50:28 2007
+++ ext/oci8/oraconf.rb	Thu Apr 12 10:58:36 2007
@@ -197,6 +197,8 @@
     when /darwin/
       @@ld_envs = %w[DYLD_LIBRARY_PATH]
       so_ext = 'dylib'
+    when /freebsd/
+      return "/usr/local/oracle8-client/lib"
     end
 
     glob_name = "#{oci_basename}.#{so_ext}#{oci_glob_postfix}"
@@ -720,7 +722,8 @@
       @libs = get_libs("#{ic_dir}/sdk")
       ld_path = nil
     else
-      @cflags = " -I#{inc_dir}"
+      @cflags = ''
+      @libs = ''
       # set ld_path and so_ext
       case RUBY_PLATFORM
       when /aix/
@@ -736,10 +739,16 @@
       when /darwin/
         ld_path = 'DYLD_LIBRARY_PATH'
         so_ext = 'dylib'
+      when /freebsd/
+        so_ext = 'a'
+        inc_dir = "#{ic_dir}/../rdbms/demo"
+        @cflags = " -I#{ic_dir}/../rdbms/public"
+        @libs = " -lcompat"
       else
         ld_path = 'LD_LIBRARY_PATH'
         so_ext = 'so'
       end
+      @cflags += " -I#{inc_dir}"
       # check Oracle client library.
       unless File.exists?("#{lib_dir}/libclntsh.#{so_ext}")
         files = Dir.glob("#{lib_dir}/libclntsh.#{so_ext}.*")
@@ -761,7 +770,7 @@
         end
         raise 'failed'
       end
-      @libs = " -L#{lib_dir} -lclntsh "
+      @libs += " -L#{lib_dir} -lclntsh "
     end
     unless File.exists?("#{inc_dir}/oci.h")
           raise <<EOS

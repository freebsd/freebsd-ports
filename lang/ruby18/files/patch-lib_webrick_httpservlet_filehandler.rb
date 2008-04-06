--- lib/webrick/httpservlet/filehandler.rb	2007-02-13 02:01:19.000000000 +0300
+++ lib/webrick/httpservlet/filehandler.rb	2008-03-03 17:36:04.000000000 +0300
@@ -163,6 +163,7 @@
             end
           end
         end
+        prevent_directory_traversal(req, res)
         super(req, res)
       end
 
@@ -198,6 +199,22 @@
 
       private
 
+      def prevent_directory_traversal(req, res)
+        # Preventing directory traversal on DOSISH platforms;
+        # Backslashes (0x5c) in path_info are not interpreted as special
+        # character in URI notation. So the value of path_info should be
+        # normalize before accessing to the filesystem.
+        if File::ALT_SEPARATOR
+          # File.expand_path removes the trailing path separator.
+          # Adding a character is a workaround to save it.
+          #  File.expand_path("/aaa/")        #=> "/aaa"
+          #  File.expand_path("/aaa/" + "x")  #=> "/aaa/x"
+          expanded = File.expand_path(req.path_info + "x")
+          expanded[-1, 1] = ""  # remove trailing "x"
+          req.path_info = expanded
+        end
+      end
+
       def exec_handler(req, res)
         raise HTTPStatus::NotFound, "`#{req.path}' not found" unless @root
         if set_filename(req, res)
@@ -256,7 +273,7 @@
 
       def check_filename(req, res, name)
         @options[:NondisclosureName].each{|pattern|
-          if File.fnmatch("/#{pattern}", name)
+          if File.fnmatch("/#{pattern}", name, File::FNM_CASEFOLD)
             @logger.warn("the request refers nondisclosure name `#{name}'.")
             raise HTTPStatus::NotFound, "`#{req.path}' not found."
           end
@@ -310,7 +327,7 @@
 
       def nondisclosure_name?(name)
         @options[:NondisclosureName].each{|pattern|
-          if File.fnmatch(pattern, name)
+          if File.fnmatch(pattern, name, File::FNM_CASEFOLD)
             return true
           end
         }

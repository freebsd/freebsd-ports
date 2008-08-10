--- lib/webrick/httputils.rb.orig	2008-08-10 14:29:50.000000000 +0400
+++ lib/webrick/httputils.rb	2008-08-10 14:30:34.000000000 +0400
@@ -23,16 +23,8 @@
       ret = path.dup
 
       ret.gsub!(%r{/+}o, '/')                    # //      => /
-      while ret.sub!(%r{/\.(/|\Z)}o, '/'); end   # /.      => /
-      begin                                      # /foo/.. => /foo
-        match = ret.sub!(%r{/([^/]+)/\.\.(/|\Z)}o){
-          if $1 == ".."
-            raise "abnormal path `#{path}'"
-          else
-            "/"
-          end
-        }
-      end while match
+      while ret.sub!(%r'/\.(?:/|\Z)', '/'); end  # /.      => /
+      while ret.sub!(%r'/(?!\.\./)[^/]+/\.\.(?:/|\Z)', '/'); end # /foo/.. => /foo
 
       raise "abnormal path `#{path}'" if %r{/\.\.(/|\Z)} =~ ret
       ret
@@ -154,8 +146,8 @@
     module_function :parse_header
 
     def split_header_value(str)
-      str.scan(/((?:"(?:\\.|[^"])+?"|[^",]+)+)
-                (?:,\s*|\Z)/xn).collect{|v| v[0] }
+      str.scan(%r'\G((?:"(?:\\.|[^"])+?"|[^",]+)+)
+                    (?:,\s*|\Z)'xn).flatten
     end
     module_function :split_header_value
 

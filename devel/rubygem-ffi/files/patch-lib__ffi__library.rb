--- ./lib/ffi/library.rb.orig	2014-08-22 21:57:09.968099978 +0000
+++ ./lib/ffi/library.rb	2014-08-22 21:57:30.351098318 +0000
@@ -114,9 +114,9 @@
 
             rescue Exception => ex
               ldscript = false
-              if ex.message =~ /(([^ \t()])+\.so([^ \t:()])*):([ \t])*invalid ELF header/
-                if File.read($1) =~ /GROUP *\( *([^ \)]+) *\)/
-                  libname = $1
+              if ex.message =~ /(([^ \t()])+\.so([^ \t:()])*):([ \t])*(invalid ELF header|file too short|invalid file format)/
+                if File.read($1) =~ /(?:GROUP|INPUT) *\( *([^\)]+)/
+                  libname = $1.split(' ')[0]
                   ldscript = true
                 end
               end

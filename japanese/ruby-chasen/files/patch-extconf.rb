--- extconf.rb.orig	Thu Sep  9 05:57:36 1999
+++ extconf.rb	Sun Aug 29 21:26:29 2004
@@ -1,20 +1,7 @@
 require "mkmf"
-require "parsearg"
 
-def usage()
-  printf "Usage:\n"
-  printf "%s [-L library_path]\n", $0
-end
-
-$USAGE = 'usage'
-parseArgs(0, "L", nil, "L:.")
-
-unless have_library("chasen", "chasen_getopt_argv")
-   $objs = Dir["*.{c,cc}"]
-   for f in $objs
-      f.sub!(/\.(c|cc)$/, ".o")
-   end
-   $objs.push File.join(["#{$OPT_L}", "libchasen.a"])
-end
+dir_config("chasen")
 
+have_library("stdc++")
+have_library("chasen", "chasen_getopt_argv") &&
 create_makefile("chasen")

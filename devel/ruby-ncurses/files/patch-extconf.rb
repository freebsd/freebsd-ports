--- extconf.rb.orig	Tue Feb 12 18:37:54 2002
+++ extconf.rb	Wed Feb 13 13:46:12 2002
@@ -7,2 +7,4 @@
 
+have_library("stdc++", "cerr")
+
 have_header("unistd.h")
@@ -38,19 +40 @@
 create_makefile('ncurses')
-
-makefile = IO.readlines("Makefile").collect{|line|
-	line.chomp!
-	line.gsub("gcc", "g++")
-}	
-
-line_no = makefile.index(makefile.grep(/^install:/)[0])
-
-makefile[line_no] += " $(rubylibdir)$(target_prefix)/ncurses.rb\n" +
-  "$(rubylibdir)$(target_prefix)/ncurses.rb: ncurses.rb        \n" +
-  "\tif test -e $(sitelibdir)$(target_prefix)/ncurses.rb; then echo This file is probably a leftover from ncurses-ruby-0.1; rm -i $(sitelibdir)$(target_prefix)/ncurses.rb; fi\n" +
-  "\t@$(RUBY) -r ftools -e 'File::install(ARGV[0], ARGV[1], 0644, true)' " +
-  "                   ncurses.rb $(rubylibdir)$(target_prefix)/ncurses.rb"
-
-
-File.open("Makefile", "w") {|f|
-  f.puts(makefile)
-}

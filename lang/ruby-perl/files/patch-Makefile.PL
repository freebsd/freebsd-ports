--- Ruby/Makefile.PL.orig	Fri Sep 15 09:45:40 2000
+++ Ruby/Makefile.PL	Sat Jun  9 11:03:11 2001
@@ -7,3 +7,3 @@
 ##$archdir = `$RUBY -rrbconfig -e 'include Config; print CONFIG["libdir"]+"/"+CONFIG["ruby_install_name"]+"/"+CONFIG["arch"], "\n"'`;
-$archdir = `$RUBY -rmkmf -e 'print \$hdrdir,"\n"'`;
+$archdir = `$RUBY -rmkmf -e 'puts Config::CONFIG["archdir"] || \$hdrdir'`;
 

--- Makefile.PL.orig	2013-10-29 14:04:03.000000000 +0800
+++ Makefile.PL	2013-10-29 14:04:10.000000000 +0800
@@ -11,7 +11,7 @@ use Config;
 
 sub MY::postamble {
     q{
-INSTALLLIB = $(PERLPREFIX)/lib
+INSTALLLIB = $(DESTDIR)$(PERLPREFIX)/lib
 
 install::
 	cp project_dir.mk $(INSTALLLIB)

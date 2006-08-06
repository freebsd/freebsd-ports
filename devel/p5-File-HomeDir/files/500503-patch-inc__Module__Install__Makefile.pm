--- ./inc/Module/Install/Makefile.pm.orig	Sat Aug  5 15:05:30 2006
+++ ./inc/Module/Install/Makefile.pm	Sat Aug  5 15:05:52 2006
@@ -175,6 +175,9 @@
     $makefile =~ s/^PERL_LIB = .+/PERL_LIB =/m;
     #$makefile =~ s/^PERL_ARCHLIB = .+/PERL_ARCHLIB =/m;
 
+    # Perl 5.005 mentions PERL_LIB explicitly, so we have to remove that as well.
+    $makefile =~ s/("?)-I\$\(PERL_LIB\)\1//g;
+
     # XXX - This is currently unused; not sure if it breaks other MM-users
     # $makefile =~ s/^pm_to_blib\s+:\s+/pm_to_blib :: /mg;
 

--- scripts/createAMMakefile.pl.orig	Sun May 30 14:41:40 2004
+++ scripts/createAMMakefile.pl	Sun May 30 14:42:35 2004
@@ -56,6 +56,7 @@
 	}
 }
 
+chmod 0644, "../Makefile.am";
 open (CLIENT, ">../Makefile.am") || die "ERROR: Failed to write to ../Makefile.am";
 print CLIENT "SUBDIRS = src\n\n";
 print CLIENT "docdir = \@docdir\@\n\n";
@@ -65,6 +66,7 @@
 
 my @clientfiles = getFiles("../src/scorched/scorched.vcproj");
 
+chmod 0644, "../src/scorched/Makefile.am";
 open (CLIENT, ">../src/scorched/Makefile.am") || die "../src/scorched/Makefile.am";
 
 print CLIENT << "EOF";

--- Makefile.PL.orig	Sat Jul 29 17:27:55 2006
+++ Makefile.PL	Sat Jul 29 17:28:17 2006
@@ -2,20 +2,20 @@
 use ExtUtils::MakeMaker qw/WriteMakefile prompt/;
 
 my (@program, @extra_modules);
-print <<"END_NOTE";
+#print <<"END_NOTE";
+#
+#The 'aiprolog' shell is optional.  If you choose to install it, Term::ReadLine
+#and Term::ReadKey will be added to your list of prerequisites.
+#
+#END_NOTE
 
-The 'aiprolog' shell is optional.  If you choose to install it, Term::ReadLine
-and Term::ReadKey will be added to your list of prerequisites.
-
-END_NOTE
-
-if (prompt("Do you wish to install the 'aiprolog' shell?", "y") =~ /^[Yy]/) {
+#if (prompt("Do you wish to install the 'aiprolog' shell?", "y") =~ /^[Yy]/) {
     @program       = (EXE_FILES => [ "bin/aiprolog" ]);
     @extra_modules = (
         'Term::ReadLine' => 1.01,
         'Term::ReadKey'  => 2.21,
     );
-}
+#}
 
 WriteMakefile(
     'NAME'		    => 'AI::Prolog',

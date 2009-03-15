--- Makefile.PL.orig	2009-03-06 18:13:08.180626799 +0000
+++ Makefile.PL	2009-03-06 18:31:21.460741171 +0000
@@ -17,10 +17,9 @@
 my @OSes = ();
 my @notOSes = ();
 
-print "I will now ask you some questions to make sure I've detected your\n";
-print "system correctly.  Most platforms will be detected several times.\n";
-print "This is deliberate.  To see an explanation of some of the more\n";
-print "obscure options, hit the question mark key.\n\n";
+print "To make this process automatic answer 'Yes' will be assumed to\n";
+print "all the following questions.  If this is not correct break the\n";
+print "process and contact port maintainer.\n\n";
 
 findOSes(File::Spec->catdir(qw(lib Devel AssertOS)));
 
@@ -44,10 +43,8 @@
         }
         next if($@);
         my $hasexpn = $classname->can('expn') ? '/?' : '';
-   ASK: my $answer = prompt(
-            "Are you using $prompt_modname? [Y/n$hasexpn]",
-            "Y"
-        );
+   ASK: my $answer = 'yes';
+   	print "Are you using $prompt_modname? [Y/n$hasexpn] Y\n";
         if($answer =~ /^y/i) {
             push @OSes, $prompt_modname;
         } elsif($answer =~ /^\?/) {

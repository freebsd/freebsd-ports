--- Makefile.PL.orig	2020-12-02 01:28:23 UTC
+++ Makefile.PL
@@ -37,10 +37,7 @@ my %tables = 
            ]
      );
 
-my @exe_files = qw(bin/enc2xs
-           bin/piconv
-           bin/encguess
-           );
+my @exe_files = qw();
 my @more_exe_files = qw(
             unidump
             );

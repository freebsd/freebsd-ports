--- cpan/Pod-Perldoc/lib/Pod/Perldoc.pm.orig	2015-12-16 03:15:45 UTC
+++ cpan/Pod-Perldoc/lib/Pod/Perldoc.pm
@@ -1931,6 +1931,7 @@ sub page {  # apply a pager to the outpu
                 # fix visible escape codes in ToTerm output
                 # https://bugs.debian.org/758689
                 local $ENV{LESS} = defined $ENV{LESS} ? "$ENV{LESS} -R" : "-R";
+                local $ENV{MORE} = defined $ENV{MORE} ? "$ENV{MORE} -R" : "-R";
                 last if system("$pager \"$output\"") == 0;
             }
         }

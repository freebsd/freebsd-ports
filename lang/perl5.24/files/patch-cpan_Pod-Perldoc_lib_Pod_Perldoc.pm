--- cpan/Pod-Perldoc/lib/Pod/Perldoc.pm.orig	2016-07-25 09:12:21 UTC
+++ cpan/Pod-Perldoc/lib/Pod/Perldoc.pm
@@ -1936,6 +1936,7 @@ sub page {  # apply a pager to the outpu
                 # fix visible escape codes in ToTerm output
                 # https://bugs.debian.org/758689
                 local $ENV{LESS} = defined $ENV{LESS} ? "$ENV{LESS} -R" : "-R";
+                local $ENV{MORE} = defined $ENV{MORE} ? "$ENV{MORE} -R" : "-R";
                 last if system("$pager \"$output\"") == 0;
             }
         }

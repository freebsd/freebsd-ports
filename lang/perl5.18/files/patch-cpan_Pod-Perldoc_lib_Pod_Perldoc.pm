--- cpan/Pod-Perldoc/lib/Pod/Perldoc.pm.orig	2014-10-01 01:32:59 UTC
+++ cpan/Pod-Perldoc/lib/Pod/Perldoc.pm
@@ -1754,6 +1754,10 @@ sub page {  # apply a pager to the outpu
             if ($self->is_vms) {
                 last if system("$pager $output") == 0;
             } else {
+                # fix visible escape codes in ToTerm output
+                # https://bugs.debian.org/758689
+                local $ENV{LESS} = defined $ENV{LESS} ? "$ENV{LESS} -R" : "-R";
+                local $ENV{MORE} = defined $ENV{MORE} ? "$ENV{MORE} -R" : "-R";
                 last if system("$pager \"$output\"") == 0;
             }
         }

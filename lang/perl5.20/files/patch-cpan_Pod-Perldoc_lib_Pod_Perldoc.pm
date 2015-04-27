--- cpan/Pod-Perldoc/lib/Pod/Perldoc.pm.orig	2014-12-27 11:49:22 UTC
+++ cpan/Pod-Perldoc/lib/Pod/Perldoc.pm
@@ -1892,6 +1892,10 @@ sub page {  # apply a pager to the outpu
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

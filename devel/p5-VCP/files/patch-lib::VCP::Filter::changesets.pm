--- lib/VCP/Filter/changesets.pm.orig	Fri Jan 30 10:48:34 2004
+++ lib/VCP/Filter/changesets.pm	Sun Jul 18 01:39:02 2004
@@ -666,8 +666,8 @@
          if ( !$change ) {
             my @future_indexes =
                grep $_ != $r_index,
-               unpack "w*", $changes->[$change_index]
-               if $changes->[$change_index];
+               unpack "w*",
+               exists $changes->[$change_index] ? $changes->[$change_index] : '';
 
             undef $changes->[$change_index];
 
@@ -780,7 +780,7 @@
 
          my $r_index = delete $self->{INDEXES_BY_ID}->{$r->id};
 
-         if ( $children->[$r_index] ) {
+         if ( exists $children->[$r_index] ) {
             push @cur_indexes, unpack "w*", $children->[$r_index];
          }
          undef $children->[$r_index];  ## undef $foo releases extra memory
